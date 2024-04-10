#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int P = 967301053;

int B;

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  B = (rng() % (P - 100)) + 50;

  int n, m = 0;
  string s;
  cin >> n >> s;
  vector<int> cnt(n + 1);
  for (int i = 1; i <= n; ++i) cnt[i] = cnt[i - 1] + (s[i - 1] == '1');
  vector<int> vec;
  for (int i = 1; i <= n; ++i)
    if (s[i - 1] == '0') {
      vec.push_back(cnt[i] & 1);
      ++m;
    }
  vector<int> hs0(m + 1), hs1(m + 1);
  vector<int> pwB(m + 1);
  pwB[0] = 1;
  for (int i = 0; i < m; ++i) pwB[i + 1] = pwB[i] * (ll)B % P;
  for (int i = 0; i < m; ++i) {
    hs0[i + 1] = (hs0[i] * (ll)B + vec[i]) % P;
    hs1[i + 1] = (hs1[i] * (ll)B + !vec[i]) % P;
  }
  int q;
  cin >> q;
  function<int(const vector<int>&, int, int)> collect = [&](const vector<int>& hs, int l, int r) {
    return (hs[r] + hs[l] * (ll)(P - pwB[r - l])) % P;
  };
  function<bool(int, int, int)> query = [&](int l1, int l2, int len) {
    --l1; --l2;
    if (cnt[l1 + len] - cnt[l1] != cnt[l2 + len] - cnt[l2]) return false;
    return collect((cnt[l1] & 1) ? hs1 : hs0, l1 - cnt[l1], l1 + len - cnt[l1 + len])
           == collect((cnt[l2] & 1) ? hs1 : hs0, l2 - cnt[l2], l2 + len - cnt[l2 + len]);
  };
  while (q--) {
    int l1, l2, len;
    cin >> l1 >> l2 >> len;
    cout << (query(l1, l2, len) ? "Yes\n" : "No\n");
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}