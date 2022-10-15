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
#define MAX (1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int n, m, a, b, ans;
vi edge[N];
bool vis[N];
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    edge[b].pb(a);
    edge[a].pb(b);

  }
  
  for(int i = 1; i <= n; i++){
    if(vis[i])continue;
    queue <int> q;
    q.push(i); 
    vis[i] = 1;
    bool b = 1;
    while(!q.empty()){
      int nd = q.front();
      q.pop();
      vis[nd] = 1;
      b &= (edge[nd].size() == 2);
      for(auto a : edge[nd])if(!vis[a])q.push(a);
    }
    ans += b;
  }

  cout << ans;
}