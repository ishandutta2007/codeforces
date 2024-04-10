#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ostream &operator<<(ostream &os, const pair<char, int> &unit) {
  return os << unit.first << "^" << unit.second;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int W = 63;

int main() {

  auto ask = [&](const vector<int> &pos) {
    if (pos.size() == 0) {
      return 0ull;
    }
    cout << "? " << pos.size() << ' ' << pos << endl;
    ull ret;
    cin >> ret;
    return ret;
  };

  int n;
  cin >> n;

  vector<int> code(n), imap(1 << 13);
  {
    int j = 0;
    for (int i = 0; i < n; ++i) {
      while (__builtin_popcount(j) != 6) ++j;
      imap[j] = i;
      code[i] = j++;
    }
  }
  vector<int> pos(W);
  for (int i = 0; i < 13; ++i) {
    vector<int> cand;
    for (int j = 0; j < n; ++j)
      if ((code[j] >> i) & 1)
        cand.push_back(j + 1);
    ull res = ask(cand);
    for (int j = 0; j < W; ++j)
      if ((res >> j) & 1)
        pos[j] |= 1 << i;
  }
  vector<ull> ans(n);
  for (int i = 0; i < W; ++i) {
    if (pos[i]) {
      for (int j = 0; j < n; ++j)
        ans[j] |= 1ull << i;
      if (__builtin_popcount(pos[i]) == 6) {
        ans[imap[pos[i]]] ^= 1ull << i;
      }
    }
  }
  cout << "! " << ans << endl;

  return 0;
}