#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define dotc()  int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)   (int)x.size()
#define eb      emplace_back
#define pb      push_back
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi      first
#define se      second
#define mod     1000000007

using ll = long long;
using vi = vector<int>;

struct Visitor {
  int pay, count, id;
  bool operator<(const Visitor& o) const {
    return pay < o.pay;
  }
};

struct Table {
  int capacity, id;
  bool operator<(const Table& o) const {
    return capacity < o.capacity;
  }
  bool operator<(const int i) const {
    return capacity < i;
  }
};

int main() {
  ioThings();

  int n; cin >> n;
  vector<Visitor> visitors(n);
  for (int i = 0; i < n; i++) {
    visitors[i].id = i + 1;
    cin >> visitors[i].count >> visitors[i].pay;
  }
  sort(rall(visitors));

  int k; cin >> k;
  vector<Table> tables(k);
  for (int i = 0; i < k; i++) {
    tables[i].id = i + 1;
    cin >> tables[i].capacity;
  }
  sort(all(tables));

  vector<pair<int, int>> ac;
  int earn = 0;
  for (auto& i : visitors) {
    auto table = lower_bound(all(tables), i.count);
    if (table != tables.end()) {
      earn += i.pay;
      ac.eb(i.id, table->id);
      tables.erase(table);
    }
  }

  cout << sz(ac) << ' ' << earn << '\n';
  for (auto& i : ac)
    cout << i.fi << ' ' << i.se << '\n';

  return 0;
}