#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

template<typename T>
struct SparseTable
{
  int n;
  vector<vector<T>> mat;

  SparseTable(const vector<T>& a)
  {
    n = int(a.size());
    int maxLog = 32 - __builtin_clz(n);
    mat.resize(maxLog);
    mat[0] = a;
    for (int j = 1; j < maxLog; j++)
    {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++)
        mat[j][i] = max(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
    }
  }

  T get(int from, int to)
  {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 31 - __builtin_clz(to - from + 1);
    return max(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

const int N = 300300;
const int oo = 27081993;

vector<int> adj[N];
vector<int> a, id, low, high;
SparseTable<int> *st;

int build(int l, int r)
{
  int maxVal = st->get(l, r), cur = id[maxVal];
  if (l < cur)
    adj[cur].push_back(build(l, cur - 1));
  if (cur < r)
    adj[cur].push_back(build(cur + 1, r));
  return cur;
}

// return max value of this subtree + 1
int go(int x, int curHigh)
{
  high[x] = curHigh;
  for (int y : adj[x])
    low[x] = max(low[x], go(y, a[x] ? min(curHigh, a[x] - 1) : curHigh));
  return a[x] ? max(low[x], a[x] + 1) : low[x];
}

pair<int, int> solve(vector<pair<int, int>> &segs, multiset<int> &s)
{
  multiset<pair<int, int>> active;
  int j = 0;
  for (int x : s)
  {
    while (j < size(segs))
    {
      auto [l, r] = segs[j];
      if (l > x)
        break;
      active.insert({r, l});
      j++;
    }

    auto u = active.lower_bound(make_pair(x, 0));
    if (u == end(active))
      return {-1, oo};
    active.erase(u);
  }

  if (j < size(segs)) return make_pair(segs[j].second, segs[j].first);
  else if (empty(active)) return {0, 0};
  else return *begin(active);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, q;
    cin >> n >> q;
    id = a = low = high = vector<int>(n);

    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
      cin >> p[i];
      id[--p[i]] = i;
      adj[i].clear();
    }
    st = new SparseTable<int>(p);
    int root = build(0, n - 1); // build tree

    int k = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if (!a[i])
        k++;
    }

    go(root, 1e6); // compute low + high for each node

    multiset<int> s;
    for (int i = 0; i < k - 1; i++)
    {
      int x;
      cin >> x;
      s.insert(x);
    }

    vector<int> queries(q);
    for (int &x : queries)
      cin >> x;

    vector<pair<int, int>> segs;
    int ans = 1;
    for (int i = 0; i < n; i++)
      if (!a[i]) segs.push_back({low[i], high[i]});
      else if (a[i] < low[i] || a[i] > high[i]) ans = 0;

    if (!ans)
    {
      for (int i = 0; i < q; i++)
        cout << "NO\n";
      continue;
    }

    sort(begin(segs), end(segs));
    auto [ansHigh, ansLow] = solve(segs, s);
    for (int low = 1; low < ansLow;)
    {
      int mid = (low + ansLow - 1) / 2;
      s.insert(mid);
      auto [u, _] = solve(segs, s);
      if (u >= 0) ansLow = mid;
      else low = mid + 1;
      s.erase(s.find(mid));
    }

    for (int high = 1e6; ansHigh < high;)
    {
      int mid = (ansHigh + 1 + high) / 2;
      s.insert(mid);
      auto [u, _] = solve(segs, s);
      if (u >= 0) ansHigh = mid;
      else high = mid - 1;
      s.erase(s.find(mid));
    }

    for (int x : queries)
      cout << (ansLow <= x && x <= ansHigh ? "YES" : "NO") << '\n';
  }
}