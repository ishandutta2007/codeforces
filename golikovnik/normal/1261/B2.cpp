#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

// order_of_key
// find_by_order
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  map<int, vector<int>> mp;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mp[x].push_back(i);
    a[i] = x;
  }
  int q;
  cin >> q;
  struct query {
    int size;
    int pos;
    int i;
  };
  vector<query> qs(q);
  for (int i = 0; i < q; ++i) {
    cin >> qs[i].size >> qs[i].pos;
    qs[i].pos--;
    qs[i].i = i;
  }
  sort(qs.begin(), qs.end(), [](auto const& x, auto const& y) {
    return x.size < y.size;
  });
  vector<int> answer(q);

  ordered_set indices;
  int sz = 0;
  int qi = 0;
  for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
    for (auto i : it->second) {
      ++sz;
      indices.insert(i);
      while (qi < q && qs[qi].size == sz) {
        answer[qs[qi].i] = *indices.find_by_order(qs[qi].pos);
        ++qi;
      }
    }
  }
  for (int x : answer) {
    cout << a[x] << '\n';
  }
  return 0;
}