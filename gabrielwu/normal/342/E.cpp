#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

vector<vi> adj, children, ancestors;
vi parent, depth;

void init_tree(int n, int root=0){
  /*Initializes depth, parent, children, ancestors(for LCA).*/
  children = vector<vi>(n);
  ancestors = vector<vi>(n);
  parent = vi(n);
  depth = vi(n);
  root = 0;
  depth[root] = 0;

  //DFS
  vector<bool> visited(n,false);
  stack<int> s;
  s.push(root);
  while(!s.empty()){
      int node = s.top(); s.pop();
      visited[node] = true;
      for(int c: adj[node]){
          if(!visited[c]){
              s.push(c);
              parent[c] = node;
              children[node].pb(c);
              depth[c] = depth[node]+1;
          }
      }
  }


  //Initialize LCA
  s.push(root);
  while(!s.empty()){
      int node = s.top();
      s.pop();
      for(int c: children[node]){
          s.push(c);
          ancestors[c].pb(node);
          for(int i=0; (1<<(i+1)) <= depth[c]; i++){
              ancestors[c].pb(ancestors[ancestors[c][i]][i]);
          }
      }
  }
}

int LCA(int node1, int node2){
    if(node1 == node2){
        return node1;
    }

    //Depths are the same
    if(depth[node1] == depth[node2]){
        for(int i=ancestors[node1].size()-1; i>=0; i--){
            if(ancestors[node1][i] != ancestors[node2][i]){
                return LCA(ancestors[node1][i],ancestors[node2][i]);
            }
        }
        return ancestors[node1][0];
    }

    //The depths are different
    if(depth[node1] > depth[node2]){    //Ensure that node2 is deeper than node1
        swap(node1, node2);
    }
    int i=0;
    while((1 << (i+1)) <= depth[node2] - depth[node1]){
        i++;
    }
    return LCA(node1,ancestors[node2][i]);
}

int dist(int u, int v) {
  int lc = LCA(u, v);
  return depth[u] + depth[v] - 2 * depth[lc];
}


vb vis;
vi sz, cent_par;
vector<vi> cent_children;


int find_size(int v, int p = -1) {
  if (vis[v]) return 0;
  sz[v] = 1;

  for (int x: adj[v]) {
    if (x != p) {
      sz[v] += find_size(x, v);
    }
  }

  return sz[v];
}
int find_centroid(int v, int p, int n) {
  for (int x: adj[v]) {
    if (x != p) {
      if (!vis[x] && sz[x] > n / 2) {
        return find_centroid(x, v, n);
      }
    }
  }

  return v;
}
void init_centroid(int v = 0, int p = -1) {
  find_size(v);

  int c = find_centroid(v, -1, sz[v]);
  vis[c] = true;
  cent_par[c] = p;
  if(p != -1)  cent_children[p].pb(c);

  for (int x: adj[c]) {
    if (!vis[x]) {
      init_centroid(x, c);
    }
  }
}

int main(){
    fast_io();
    int n, m;
    cin >> n >> m;

    adj = vector<vi>(n);
    forn(i, n-1){
      int x, y;
      cin >> x >> y;
      x--;y--;
      adj[x].pb(y);
      adj[y].pb(x);
    }

    init_tree(n, 0);
    vis = vb(n);
    sz = vi(n);
    cent_par = vi(n);
    cent_children = vector<vi>(n);


    init_centroid();

    vi closest(n, INT_MAX/2);  //closest red node in subtree

    int x = 0;
    while(x != -1){
      closest[x] = min(closest[x], dist(0, x));
      x = cent_par[x];
    }

    forn(i, m){
      int t, v;
      cin >> t >> v;
      v--;
      if(t==1){
        int x = v;
        while(x != -1){
          closest[x] = min(closest[x], dist(v, x));
          x = cent_par[x];
        }
      }else if(t==2){
        int best = closest[v];
        int x = v;
        while(x != -1){
          best = min(best, closest[x] + dist(x, v));
          x = cent_par[x];
        }
        cout << best << "\n";
      }
    }

}