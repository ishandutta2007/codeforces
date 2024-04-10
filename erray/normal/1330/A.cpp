#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define L (nd<<1)
#define R L|1
#define mid (s + e)>>1
#define ln '\n'
#define MAX (ll)(1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int t, n,x, k;
void solve(){
	cin >> n >> k;
	set <int> s; 
	bool vis[500];
	memset(vis, 0, sizeof vis);
	while(n--){cin >> x;vis[x] = 1;}
	int ans = 1;
	while(k || vis[ans]){k-=(!vis[ans]);++ans;}
	ans--;
	cout << ans << ln;
}
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL); 
  cin >> t;
  while(t--){
  	solve();
  }
}