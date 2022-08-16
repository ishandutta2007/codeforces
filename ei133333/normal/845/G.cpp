
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <iomanip>
#include <cstring>
#define fi first
#define se second
#define rep(i, x, n) for (int i = x; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> VI;
const int maxn = 100005;

int in () { int x; scanf("%d", &x); return x; }

int path[maxn], comp[maxn];
bool mark[maxn];
vector < pii > v[maxn];
vector < int > cyc[maxn];

void dfs (int cur, int id){
  comp[cur] = id;
  mark[cur] = true;
  for (int i = 0; i < SZ(v[cur]); i++){
    int nei = v[cur][i].fi, wei = v[cur][i].se;
    if (mark[nei])
      cyc[id].pb(path[cur] ^ path[nei] ^ wei);
    else{
      path[nei] = (path[cur] ^ wei);
      dfs(nei, id);
    }
  }
}

int main()
{
  int n = in();
  int m = in();
  int q = 1;
  //in();

  for (int i = 0; i < m; i++){
    int a = in() - 1;
    int b = in() - 1;
    int c = in();
    v[a].pb(mp(b, c));
    v[b].pb(mp(a, c));
  }

  for (int i = 0; i < n; i++)
    if (!mark[i]){
      dfs(i, i);
      int r = 0;
      for (int b = 30; b >= 0; b--){
        int cur;
        for (cur = r; cur < SZ(cyc[i]); cur++)
          if ( (cyc[i][cur] >> b)&1 )
            break;
        if (cur == SZ(cyc[i])) continue;
        swap(cyc[i][r], cyc[i][cur]);
        for (int j = r+1; j < SZ(cyc[i]); j++)
          if ( (cyc[i][j] >> b)&1 )
            cyc[i][j] ^= cyc[i][r];
        r++;
      }
      cyc[i].erase(cyc[i].begin() + r, cyc[i].end());
    }

  while (q--){
    //int a = in() - 1;
    //int b = in() - 1;
    int a = 0;
    int b = n - 1;

    if (comp[a] != comp[b]){
      printf("XIT\n");
      continue;
    }
    int id = comp[a];
    int ret = (path[a] ^ path[b]);
    for (int i = 0; i < SZ(cyc[id]); i++)
      ret = min(ret, ret ^ cyc[id][i]);
    printf("%d\n", ret);
  }
  return 0;
}