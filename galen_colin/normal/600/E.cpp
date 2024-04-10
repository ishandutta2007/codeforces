/* adapting this code & figuring out how it works */
/* source: https://codeforces.com/blog/entry/44351 */
/* phase 1: make it legible DONE */
/* phase 2: comment and pick apart the functions TODO */
/* phase 3: pack into a struct if applicable TODO */
/* 
  don't forget to make sure it still works after each step :)
*/
#include <bits/stdc++.h>

#define pb push_back
#define X first
#define Y second
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define ll long long

using namespace std;

/* specific to a single problem */
struct tree_dsu {
  long long n, t;
  vector<long long> par, size;
  vector<vector<int> > edges;
  /* special vars */
  vector<long long> col, mx, ans;
  vector<map<int, int> > a;

  void init(int sz) {
    n = sz;
    t = 0;
    par = vector<long long>(n);
    size = vector<long long>(n);
    edges = vector<vector<int> >(n);
    col = vector<long long>(n);
    mx = vector<long long>(n);
    ans = vector<long long>(n);
    a = vector<map<int, int> >(n);
  }

  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  /* everything here is special, think about what you need to do with this */

  /* update operation for each addition with the map */
  void upd(int s, int x, int v) {
    if (x > mx[s]) {
      mx[s] = x;
      ans[s] = v;
    }
    else if (x == mx[s]) ans[s] += v;
  }

  /* merge two sets, linearly add the smaller one to the big one */
  void mrg(int s, int v, int u) {
    for (auto &x: a[u]) upd(s, a[v][x.X] += x.Y, x.X);
  }

  /* geniosity with parents, avoid the extra log(n) factor of transferring */
  void dfs(int v = 0, int p = -1) {
    size[v] = 1;

    /* special case: leaf */
    if (!edges[v].size() || (edges[v].size() == 1 && edges[v].back() == p)){
      par[v] = t;
      a[t++][col[v]] = 1;
      ans[v] = col[v];
      mx[v] = 1;
      return;
    }

    /* dfs down, find the biggest child */
    int big = -1;
    for (auto &u: edges[v])
      if (u != p){
        dfs(u, v);
        size[v] += size[u];
        if (big == -1 || size[big] < size[u]) big = u ;
      }
    

    /* use the stuff from the biggest child */
    par[v] = par[big];
    ans[v] = ans[big];
    mx[v] = mx[big];

    /* for each child not the biggest, merge it to this one */
    for (auto &u: edges[v])
      if (u != p && u != big)
        mrg(v, par[v], par[u]);
    
    /* add this color */
    upd(v, ++a[par[v]][col[v]], col[v]);
  }
};

tree_dsu tds;
int n;
int main() {
  /* read the graph (do i really need this comment) */
  cin >> n;

  tds.init(n);
  f0r(i, n) cin >> tds.col[i];
  f0r(i, n - 1) {
    int v, u; cin >> v >> u;
    tds.edge(--v, --u);
  }

  /* do magic voodoo offline computation */
  tds.dfs();

  /* print the answer (do i really need this comment) */
  f0r(i, n) {
    if (i) cout << " ";
    cout << tds.ans[i];
  }
  cout << endl;
}