#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rng(i, a, b) for(int i=(int)a;i<int(b);i++)
#define rep(i, b) rng(i, 0, b)
#define repn(i, b) rng(i, 1, b+1)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define si(x) int(x.size())

#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0);
#endif

template<class t, class u>bool chmax(t&a, u b){if(a<b){a=b;return true;}else return false;}
template<class t, class u>bool chmin(t&a, u b){if(b<a){a=b;return true;}else return false;}

template<class t, class u>
ostream& operator<<(ostream& os, const pair<t,u>& p){
	return os<<"{"<<p.first<<","<<p.second<<"}";
}

template<class t>ostream& operator<<(ostream& os, const vector<t>&v){
	os<<"{";
	for(auto e:v) os<<e<<",";
	return os<<"}";
}
template<class t>using vc=vector<t>;
using P=pair<int,int>;
#define a first
#define b second

void solve(){
	int n, k; cin >> n >> k;
	vc<int>vec(n+1);
	vc<int>rui(n+1);
	repn(i, n) cin >> vec[i];
	repn(i, n) rui[vec[i]] ++;
	repn(i, n) rui[i] += rui[i-1];
	
	P p = P(-n, n);
	repn(l, n){
		int now = rui[l-1];
		if((rui[n]-now)*2-n < k) continue;
		int lb = l-1, ub = n;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			if((rui[mid]-now)*2-n >= k) ub = mid;
			else lb = mid;
		}
		if(p.b-p.a > ub-l) p = P(l, ub);
	}
	cout << p.a << " " << p.b << '\n';
	vc<int>rui2(n+1);
	vc<int>pos(n+1, -1);
	pos[0] = 0;
	repn(i, n){
		rui2[i] = rui2[i-1];
		if(p.a <= vec[i] and vec[i] <= p.b) rui2[i] ++;
		else rui2[i] --;
		
		if(1 <= rui2[i] and rui2[i] < k and pos[rui2[i]] == -1){
			pos[rui2[i]] = i;
		}
	}
	pos[k] = n;
	for(int i=0;i<k;i++) cout << pos[i]+1 << " " << pos[i+1] << '\n';
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
	
	int t; cin >> t;
	while(t -- ) solve();
}