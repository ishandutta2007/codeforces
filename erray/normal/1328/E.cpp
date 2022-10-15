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
int n, m, a, b, lca[N][32], d[N], pw[N];
vi edge[N];
void build(){
  queue<pii> q;
  q.push(mp(1, -1));
  d[1] = 1; 
  while(!q.empty()){
    int nd = q.front().st, par = q.front().nd;
    lca[nd][0] = par;
    //cout << nd << " " << par << ln;
    q.pop();
    for(auto a : edge[nd]){
      if(a == par)continue;
      else {
        d[a] = d[nd] + 1;
        q.push(mp(a, nd));
      }
    }
  }
  for(int i = 1; i < 30; i++){
    for(int nd = 1; nd <= n; nd++){
      lca[nd][i] = lca[lca[nd][i - 1]][i -1];
      //cout << lca[nd][i] << " ";
    }
  }
}
bool LCA(int nd1, int nd2){
  if(d[nd1] < d[nd2])swap(nd1, nd2);
  int lev = d[nd1] - d[nd2];
  for(int i = 30; i >= 0; i--){
    //cout << lev << " " << pw[i] << ln;
    if(lev >= pw[i]){nd1 = lca[nd1][i];lev-= pw[i];}
  }
  //cout << nd2 << " " << nd1 << ln;
  return (nd2 == nd1 | lca[nd2][0] == lca[nd1][0]);
}
bool query(vi lst){ 
  bool r = 1;
  for(int i = 0; i < lst.size() - 1; i++)r &= LCA(lst[i],lst[i + 1]);
  return r;
}
bool cmp(int a1, int a2){
  return d[a1] > d[a2];
}
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  pw[0] = 1;
  for(int i = 1; i < 32; i++)pw[i] = pw[i - 1] * 2;
  cin >> n >> m;
  for(int i = 0; i < n- 1; i++){
    cin >> a >> b;
    edge[a].pb(b);
    edge[b].pb(a);
  }
  build();
  while(m--){
    cin >> a;
    vi v;
    while(a--){
      cin >> b;
      v.pb(b);
    }
    sort(all(v), cmp);
    cout << (query(v) ? "YES" : "NO") << ln;
  }
}