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

int n, m, a[(1<<21)];

void solve(){
	cin >> n >> m;
	ll ans = 0;
	rep(i, (2<<n)) a[i] = 0;
	rep(i, (1<<n)-1){
		cin >> a[i]; ans += a[i];
	}
	int zan = (1<<n) - (1<<m);
	vector<int>vec;
	rep(i, (1<<n)-1){
		while(zan){
			if(a[i] == 0) break;
			int cur = i;
			while(1){
				if(a[cur*2+1] == 0 && a[cur*2+2] == 0){
					if(cur < (1<<m)-1){
						break;
					}
					goto nxt;
				}
				else if(a[cur*2+1] > a[cur*2+2]){
					cur = cur*2+1;
				}
				else cur = cur*2+2;
			}
			break;
			nxt:;
			zan --;
			vec.pb(i);
			cur = i; ans -= a[cur];
			while(1){
				if(a[cur*2+1] == 0 && a[cur*2+2] == 0){
					a[cur] = 0; break;
				}
				else if(a[cur*2+1] > a[cur*2+2]){
					a[cur] = a[cur*2+1];
					cur = cur*2+1;
				}
				else{
					a[cur] = a[cur*2+2];
					cur = cur*2+2;
				}
			}
		}
	}
	assert(zan == 0);
	cout << ans << '\n';
	rep(i, vec.size()) cout << ++vec[i] << " ";
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) solve();
}