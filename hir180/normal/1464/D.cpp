//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}


void solve(){
	int n; cin >> n;
	vector<int>p(n, 0);
	rep(i, n) {
		cin >> p[i]; p[i] --;
	}
	vector<int>used(n, 0);
	vector<int>cmp;
	int cnt[3] = {}, ret = 0;
	ll num = 1;
	
	rep(i, n){
		if(used[i]) continue;
		int C = 0, j = i;
		while(!used[i]){
			 used[i] = 1;
			 i = p[i];
			 C ++;
		}
		cmp.pb(C);
		ret += (C-1)/3;
		cnt[C%3] ++;
	}
	
	if(n%3 == 0){
		if(cnt[2] > cnt[1]) ret += (cnt[2]-cnt[1]) / 3;
		ret = ret + (cmp.size() + ret) - n/3;
		num = 1;
		rep(i, n/3) num = num * 3LL % mod;
	}
	else if(n%3 == 1){
		if(cnt[1] == 1 && cnt[2] == 0){
			ret = ret + (cmp.size() + ret + 1) - n/3 - 1;
		}
		else if(cnt[2]-2 > cnt[1]){
			ret += (cnt[2] - 2 - cnt[1]) / 3;
			ret = ret + (cmp.size() + ret) - n/3 - 1;
		}
		else{
			ret = ret + (cmp.size() + ret) - n/3 - 1;
		}
		num = 4;
		rep(i, n/3-1) num = num * 3LL % mod;
		
		
		//4, 3...3 !
		vector<int>cand(3, -1);
		rep(i, cmp.size()){
			if(cmp[i] >= 4){
				cand[cmp[i]%3] = i;
			}
		}
		for(auto at:cand){
			if(at == -1) continue;
			vector<int>x(3, 0);
			int R = 0;
			rep(i, cmp.size()){
				if(i != at){
					x[cmp[i]%3] ++; R += (cmp[i]-1)/3;
				}
				else{
					x[(cmp[i]-4)%3] ++; R += (cmp[i]-2)/3;
				}
			}
			if(x[2] > x[1]) R += (x[2] - x[1])/3;
			R = R + (cmp.size() + R) - n/3;
			chmin(ret, R);
		}
	}
	else{
		if(cnt[2]-1 > cnt[1]) ret += (cnt[2]-1-cnt[1]) / 3;
		ret = ret + (cmp.size() + ret) - n/3 - 1;
		num = 2;
		rep(i, n/3) num = num * 3LL % mod;
	}
	cout << num << " " << ret << '\n';
}
int main(){
	//ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) solve();
}