#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
 
using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
ll i, j;
const ll mod = 1e9 + 7;
 
ll n, q, Q, T, m, k, r, x, y, z, g;
vi edges[200001];
bool v[200001], ok[200001];
int a[200001], d[200001];
queue<int> qu;
int reach;

void dfs(int v, int depth) {
  if (d[v] != -1) return;
  d[v] = depth;
  for (int i: edges[v]) dfs(i, depth + 1);
}

set<int> b, c;

int main() {
  io;
  cin >> n;
  ms(v, 0);
  f0r(i, n-1) {
    cin >> x >> y;
    x--; y--;
    edges[x].pb(y);
    edges[y].pb(x);
  }
  f0r(i, n) {cin >> a[i]; a[i]--; }
  f0r(i, n) d[i] = -1;
  dfs(0, 0);
  bool f = 1;
  int pt = 1;
  qu.push(0);
  while (!qu.empty()) {
    int x = qu.front();
    reach = edges[x].size();
    if (x) reach--;
    qu.pop();
    for (int i: edges[x]) {
      if (d[x] < d[i]) {
        c.insert(i);
      }
    }
    int y = pt;
    for(; pt < y + reach; pt++) {
      qu.push(a[pt]);
      b.insert(a[pt]);
    }
    if (c != b) {
      f = 0;
      break;
    }
    c.clear();
    b.clear();
  }
  
  cout << (f ? "Yes" : "No") << endl;
}