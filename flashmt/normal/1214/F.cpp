#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;
const int N = 200200;

int m, n;
vector<pair<int, int>> a, b;
vector<int> toggleA[N];
vector<pair<int, int>> toggleB[N];

void initA()
{
  int l = 0, r = 0;
  for (int i = 0; i < n; i++)
  {
    while (b[l].first < a[i].first)
      l++;
    r = max(r, l);
    while (r < b.size() && b[r].first <= a[i].first + m / 2)
      r++;

    if (l + n == r) toggleA[0].push_back(i);
    else
    {
      int from = (l - i + n) % n, to = (r - i + n) % n;
      toggleA[from].push_back(i);
      toggleA[to].push_back(i);
      if (from > to)
        toggleA[0].push_back(i);
    }
  }
}

void addB(int i, int l, int r, int op)
{
  if (l == r)
    return;
  if (l + n == r) toggleB[0].push_back({i, op});
  else
  {
    int from = (i - r + n + 1) % n, to = (i - l + n + 1) % n;
    toggleB[from].push_back({i, op});
    if (to < from && to > 0)
      toggleB[0].push_back({i, op});
  }
}

void initB()
{
  vector<int> l(n * 2, 0), r(n * 2, 0);
  for (int i = 0; i < n * 2; i++)
  {
    if (i)
    {
      l[i] = l[i - 1];
      r[i] = r[i - 1];
    }
    while (l[i] < n && a[l[i]].first + m / 2 < b[i].first)
      l[i]++;
    r[i] = max(r[i], l[i]);
    while (r[i] < n && a[r[i]].first <= b[i].first)
      r[i]++;
  }

  for (int i = 0; i < n; i++)
  {
    // a + m / 2 < b => -b for [0, l)
    if (l[i] > 0)
      addB(i, 0, l[i], 0);
    // a <= b <= a + m / 2 => b for [l, r)
    addB(i, l[i], r[i], 1);
    // b < a < b + m / 2 => -b - m for [r, ll)
    if (r[i] < l[i + n])
      addB(i, r[i], l[i + n], 2);
    // b + m / 2 <= a <= b + m => b + m for [ll, rr)
    if (l[i + n] < r[i + n])
      addB(i, l[i + n], r[i + n], 3);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x;
  cin >> m >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    a.push_back({--x, i});
  }
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    b.push_back({--x, i});
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++)
    b.push_back({b[i].first + m, b[i].second});

  initA();
  initB();
  vector<int> curA, curB(n, 0);
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    curA.push_back(m + a[i].first);
    sum += m + a[i].first;
  }

  long long ans = oo;
  int bestD = -1;
  for (int d = 0; d < n; d++)
  {
    for (int i : toggleA[d])
    {
      sum -= curA[i];
      curA[i] = m - curA[i];
      sum += curA[i];
    }
    for (auto u : toggleB[d])
    {
      int i = u.first, op = u.second;
      sum -= curB[i];
      if (!op) curB[i] = -b[i].first;
      else if (op == 1) curB[i] = b[i].first;
      else if (op == 2) curB[i]= -b[i].first - m;
      else curB[i] = b[i].first + m;
      sum += curB[i];
    }

    if (sum < ans)
    {
      ans = sum;
      bestD = d;
    }
  }

  cout << ans << '\n';
  vector<int> match(n);
  for (int i = 0; i < n; i++)
    match[a[i].second] = b[(i + bestD) % n].second;
  for (int i = 0; i < n; i++)
    cout << match[i] + 1 << " \n"[i == n - 1];
}