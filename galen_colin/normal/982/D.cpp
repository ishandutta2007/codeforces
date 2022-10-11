#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e12;
const ll mod = 1e9 + 7;

multiset<ll> mset;

struct dsu {
  int n;
  vector<int> sizes, marks;
  vector<vector<int> > graph;

  void init(int rn) {
    n = rn;
    sizes = vector<int>(n);
    fill(sizes.begin(), sizes.end(), 1);
    marks = vector<int>(n);
    for (int i = 0; i < n; i++) marks[i] = i;
    graph = vector<vector<int> >(n);
  }

  void mark(int m, int node) {
    if (marks[node] == m) return;

    marks[node] = m;

    for (int i: graph[node]) mark(m, i);
  }

  void merge(int a, int b) {
    if (marks[a] == marks[b]) return;
    mset.erase(mset.find(sizes[marks[a]]));
    mset.erase(mset.find(sizes[marks[b]]));
    graph[a].push_back(b);
    graph[b].push_back(a);

    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);

    sizes[marks[b]] += sizes[marks[a]];
    sizes[marks[a]] = 0;
    mark(marks[b], a);
    mset.insert(sizes[marks[b]]);
  }

  int find(int n) { return marks[n]; }
};

dsu d;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll n; cin >> n;
  ll arr[n];

  f0r(i, n) {
    cin >> arr[i];
  }

  pll p[n + 1];

  f0r(i, n) {
    p[i] = mp(arr[i], i);
  }

  sort(p, p + n);

  p[n].f = p[n-1].f + 1;

  bool visited[n];

  ms(visited, 0);

  d.init(n);
  pll ans = mp(-1, -1);


  f0r(i, n) {
    //cout << i << endl;
    ll x = p[i].s;
    visited[x] = 1;

    mset.insert(1);

    if (x > 0 && visited[x - 1]) {
      d.merge(x - 1, x);
    }

    if (x < n-1 && visited[x + 1]) {
      d.merge(x + 1, x);
    }

    ll y = *mset.begin();
    ll z = *mset.rbegin();

    if (y == z) {
      ans = max(ans, mp((ll) (mset.size()), -(p[i].f + 1)));
    }
  }

  cout << -ans.s << endl;

  
}