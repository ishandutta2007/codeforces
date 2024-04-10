#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int const ALPHA = 26;
  using state_t = array<int, ALPHA>;

  auto sub = [](state_t& a, state_t const& b) {
    for (int i = 0; i < ALPHA; ++i) {
      a[i] -= b[i];
    }
  };
  auto any = [](state_t const& st) {
    for (int i = 0; i < ALPHA; ++i) {
      if (st[i]) {
        return i;
      }
    }
    throw;
  };

  auto ask = [](int l, int r) {
    cout << "? " << l + 1 << ' ' << r + 1 << endl;
    auto len = (r - l + 1) * (r - l + 2) / 2;
    multiset<state_t> result;
    while (len--) {
      string s;
      cin >> s;
      state_t st{};
      for (char ch : s) {
        st[ch - 'a']++;
      }
      result.insert(st);
    }
    return result;
  };
  auto a = ask(0, n - 1);
  if (n != 1) {
    auto b = ask(1, n - 1);
    auto remove = [](auto& st, auto const& x) {
      st.erase(st.find(x));
    };
    for (auto const& st : b) {
      remove(a, st);
    }
  }
  vector<state_t> pref;
  pref.emplace_back();
  pref.insert(pref.end(), a.begin(), a.end());
  sort(pref.begin(), pref.end(), [](auto const& i, auto const& j) {
    int ci = 0;
    int cj = 0;
    for (auto x : i) {
      ci += x;
    }
    for (auto x : j) {
      cj += x;
    }
    return ci < cj;
  });
  string s;
  for (int i = 0; i < n; ++i) {
    auto cur = pref[i + 1];
    sub(cur, pref[i]);
    s += ((char) ('a' + any(cur)));
  }
  cout << "! " << s << endl;
  return 0;
}