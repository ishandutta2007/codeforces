#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
#define x first
#define y second

typedef long long LL;
typedef vector<int> VI;
typedef pair<LL, LL> PII;
typedef pair<double, double> PDD;

const double PI = acos(-1.0);
const int MOD = 1000*1000*1000 + 7;
const LL LINF = MOD * (LL)MOD;

int n,m,k;
int Q;
bool f[300000];
vector<int> g[300000];
bool used[300000];
int d[2][300000];

vector<int> q;
void bfs(int wer, int index) {
  FOR (i,0,n) used[i] = false;
  q.clear();
  q.push_back(wer);
  used[wer] = true;
  int pos = 0;
  while (pos != q.size()) {
    int v = q[pos++];
    FOR (i,0,g[v].size()) {
      int to = g[v][i];
      if (used[to])
        continue;
      used[to] = true;
      d[index][to] = 1 + d[index][v];
      //cout << "dist"<<" "<<index<<" "<<to<<" "<<d[index][to];
      q.push_back(to);
    }
  }
}

int main()
{
    // freopen("houses.in", "r", stdin);
    // freopen("houses.out", "w", stdout);

  cin >> n >> m >> k;
  FOR (i,0,k) { cin >> Q; Q--; f[Q] = true;}
  FOR (i,0,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].PB(b);
    g[b].PB(a);
  }

  bfs(0,0);
  bfs(n-1,1);

  LL maxans = d[0][n-1];
  vector<PII> E;
  FOR (i,0,n)
      if (f[i])
        E.push_back(MP(d[0][i], d[1][i]));

  sort(E.begin(), E.end());
  /*FOR (i,0,k) {
    cout << E[i].first<<" * "<<E[i].second<<endl;
  }*/
  for (int index = k-2; index >=0; index--) {
    E[index].second = max(E[index].second, E[index+1].second);
  }

  LL ans = 0;
  FOR (index,0,k-1) {
    ans = max(ans, E[index].first+1+E[index+1].second);
  }

  cout << min(ans, maxans);
}