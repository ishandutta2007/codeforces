#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define fi first
#define se second
const int N=2001;
const ll mod=998244353;
ll a[N],b[N];
int n,m;

//<edge>
int eu[N],ev[N];
bool vis[N],in[N];
bool newi[N];
//</groups>
int orz[N];
vector<int>adj[N];
ll dis[N];
ll need[N];
int prv[N];
void solve(){
	ll x,y;cin >> x >> y;
	if(x*2-1<=y){
		cout << (y-1)/2 << '\n';
	}
	else{
		cout << (y-x) << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}