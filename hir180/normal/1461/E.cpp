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
ll k, l, r, t, x, y;
void solve(){
	cin >> k >> l >> r >> t >> x >> y;
	if(x == y){
		if(k+y <= r || k-y >= l) puts("Yes");
		else puts("No");
	}
	else if(x > y){
		if(k+y <= r) k+=y;
		//k + (t-1) * (y-x) - x
		if(5e18 / abs(y-x) <= t-1){
			puts("No");
		}
		else{
			if(k + (t-1) * (y-x) - x >= l) puts("Yes");
			else puts("No");
		}
	}
	else{
		if(r-y+1 > l+x-1) puts("Yes");
		else{
			map<ll, ll>dp;
			ll cur = k;
			ll zan = 0;
			while(zan < t){
			    //cout << cur << " " << zan << endl;
				if(l <= cur && cur <= r-y){
					if(dp.find(cur) == dp.end()){
						dp[cur] = zan;
						cur += y-x;
						zan ++;
						if(zan == t){
							puts("Yes"); return;
						}
					}
					else{
						ll dif = zan - dp[cur]; //cout<<dif<<endl;
						ll rem = t-zan;
						zan += (rem/dif) * dif; //cout << zan << endl;
						if(zan == t){
							puts("Yes"); return;
						}
						cur += y-x;
						zan++;
						if(zan == t){
							puts("Yes"); return;
						}
						//cout<<cur<<" "<<zan<<endl;
					}
				}
				else{
					ll need = (cur-(r-y));
					need = (need + x-1) / x;
					if(need >= t-zan){
						cur -= x*(t-zan);
						puts(cur>=l?"Yes":"No");
						return;
					}
					else{
						cur -= need * x;
						if(cur < l){
							puts("No"); return;
						}
						zan += need;
						if(zan == t) puts(cur>=l?"Yes":"No");
					}
				}
			}
		}
	}
}
int main(){
	solve();
}