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
int dp[2][1000005], n;
string str;

void solve(){
	cin >> str; n = str.size();
	rep(j, 2*n+4) dp[0][j] = dp[1][j] = 0;
	int cur = n+2;
	rep(i, n){
		int v = 1-(str[i]-'0')*2;
		if(v == -1) dp[0][cur+v] ++;
		else dp[1][cur]++;
		cur += v;
	}
  	set<int>curr[2];
  	rep(i, 2) rep(j, 2*n+4) if(dp[i][j] > 0) curr[i].insert(j);
  
	string ans = "";
	int zan = n+2;
	while(ans.size() < n){
		if(dp[1][zan]){
          	if(!dp[0][zan]){
            	bool bad = 0;
              	rep(i, 2) if(curr[i].size()) if(*curr[i].begin() < zan) bad = 1;
              	if(bad) goto nxt;
            }
			dp[1][zan]--; if(dp[1][zan]==0) curr[1].erase(zan); ans.pb('0'); zan++; 
		}
		else{
          	nxt:;
			dp[0][zan-1]--; if(dp[0][zan-1] == 0) curr[0].erase(zan-1); ans.pb('1'); zan--;
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) solve();
}