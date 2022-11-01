#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

const ll MOD = 1e9 + 7;

mt19937 gen(time(0));

vector <int> dsu;

int get(int v) {
  if (dsu[v] == v)
    return v;
  return dsu[v] = get(dsu[v]);
}

void merge(int u, int v) {
  if (gen() & 1)
    swap(u, v);
  dsu[v] = u;
}

ll binp(ll a, ll p) {
  if (!p)
    return 1;
  if (p & 1)
    return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <vector <int>> g(m + 1);
  dsu.resize(m + 1);
  iota(dsu.begin(), dsu.end(), 0);
  vector <int> res;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    int u, v;
    cin >> u;
    if (k == 2)
      cin >> v;
    else
      v = 0;
    int a = get(u), b = get(v);
    if (a == b)
      continue;
    res.push_back(i);
    merge(a, b);
  }
  cout << binp(2, (int)res.size()) << ' ' << res.size() << '\n';
  for (auto &now : res)
    cout << now << ' ';
  return 0;
}