#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

ostream& operator<<(ostream& os, const pair<char, int>& unit) {
  return os << unit.first << "^" << unit.second;
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

typedef valarray<int> Arr;

const int P = 1000000007;

int norm(int x) { return x >= P ? x - P : x; }

void add(int& x, int y) {
  ((x += y) >= P) ? (x -= P) : 0;
}

void sub(int& x, int y) {
  ((x -= y) < 0) ? (x += P) : 0;
}

void add(Arr& a, const Arr& b) {
  for (int i = 0; i < 1 << 16; ++i)
    add(a[i], b[i]);
}

void pre(Arr& a) {
  for (int i = 0; i < 16; ++i)
    for (int j = 0; j < 1 << 16; ++j)
      if ((j >> i) & 1)
        add(a[j], a[j ^ 1 << i]);
}

void ipre(Arr& a) {
  for (int i = 0; i < 16; ++i)
    for (int j = (1 << 16) - 1; j >= 0; --j)
      if ((j >> i) & 1)
        sub(a[j], a[j ^ 1 << i]);
}

void suf(Arr& a) {
  for (int i = 0; i < 16; ++i)
    for (int j = (1 << 16) - 1; j >= 0; --j)
      if ((j >> i) & 1)
        add(a[j ^ 1 << i], a[j]);
}

void isuf(Arr& a) {
  for (int i = 0; i < 16; ++i)
    for (int j = 0; j < 1 << 16; ++j)
      if ((j >> i) & 1)
        sub(a[j ^ 1 << i], a[j]);
}

Arr orMult(Arr lhs, Arr rhs) {
  pre(lhs);
  pre(rhs);
  for (int i = 0; i < 1 << 16; ++i)
    lhs[i] = lhs[i] * (ll)rhs[i] % P;
  ipre(lhs);
  return lhs;
}

Arr andMult(Arr lhs, Arr rhs) {
  suf(lhs);
  suf(rhs);
  for (int i = 0; i < 1 << 16; ++i)
    lhs[i] = lhs[i] * (ll)rhs[i] % P;
  isuf(lhs);
  return lhs;
}

char str[510];
Arr symbols[4][2];
Arr ques;

Arr getSymbol(char c) {
  if (islower(c))
    return symbols[c - 'a'][1];
  return symbols[c - 'A'][0];
}

Arr solve(int l, int r) {
  if (l == r)
    return str[l] == '?' ? ques : getSymbol(str[l]);
  int cnt = 1;
  int i = l;
  while (cnt) {
    ++i;
    if (str[i] == '(') ++cnt;
    else if (str[i] == ')') --cnt;
  }
  Arr lhs = solve(l + 1, i - 1), rhs = solve(i + 3, r - 1);
  Arr ret = Arr(1 << 16);
  if (str[i + 1] != '|')
    add(ret, andMult(lhs, rhs));
  if (str[i + 1] != '&')
    add(ret, orMult(lhs, rhs));
  return ret;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ques.resize(1 << 16);
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 2; ++j) {
      symbols[i][j].resize(1 << 16);
      for (int k = 0; k < 1 << 16; ++k) {
        bool flag = true;
        for (int l = 0; l < 16; ++l)
          if (((k >> l) & 1) != (((l >> i) & 1) ^ j)) {
            flag = false;
            break;
          }
        symbols[i][j][k] = flag;
      }
      add(ques, symbols[i][j]);
    }
  int n;
  cin >> str >> n;
  vi x(n), e(n);
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d >> e[i];
    x[i] = a | (b << 1) | (c << 2) | (d << 3);
  }
  Arr res = solve(0, strlen(str) - 1);
  int ans = 0;
  for (int i = 0; i < 1 << 16; ++i) {
    bool flag = true;
    for (int j = 0; j < n; ++j)
      if (((i >> x[j]) & 1) != e[j]) {
        flag = false;
        break;
      }
    if (flag)
      add(ans, res[i]);
  }
  cout << ans;

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}