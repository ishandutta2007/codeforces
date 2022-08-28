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
#include <iomanip>
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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

using Num = long double;

const Num EPS = 1e-7;

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> x(n), y(n), dx(n), dy(n), s(n);
  vector<Num> len(n), k(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> s[i];
    int g = gcd(abs(dx[i]), abs(dy[i]));
    dx[i] /= g;
    dy[i] /= g;
    len[i] = sqrtl(dx[i] * (ll)dx[i] + dy[i] * (ll)dy[i]);
    k[i] = (Num)dy[i] / dx[i];
    b[i] = y[i] - k[i] * x[i];
  }

  auto pred = [&](Num tim) {
    vector<Num> l(n), r(n), y1(n), y2(n);
    vector<pair<Num, int>> actions;
    for (int i = 0; i < n; ++i) {
      Num x1 = x[i], x2 = x[i] + dx[i] * tim * s[i] / len[i];
      if (x1 > x2) swap(x1, x2);
      l[i] = x1;
      r[i] = x2;
      y1[i] = x1 * k[i] + b[i];
      y2[i] = x2 * k[i] + b[i];
      actions.emplace_back(x1, i + 1);
      actions.emplace_back(x2, -i - 1);
    }
    Num current = numeric_limits<Num>::min();
    set<int, function<bool(int, int)>> lines([&](int i, int j) {
      return k[i] * current + b[i] < k[j] * current + b[j];
    });

    auto eval = [&](int i, Num xpos) {
      return k[i] * xpos + b[i];
    };

    auto side = [&](int i, int j) {
      return (eval(i, l[j]) - eval(j, l[j])) * (eval(i, r[j]) - eval(j, r[j])) <= 0;
    };

    auto check = [&](int i, int j) {
      return !(side(i, j) && side(j, i));
    };

    sort(actions.begin(), actions.end());

    //cerr <<" START \n";

    for (const auto& act : actions) {
      Num st;
      int id;
      tie(st, id) = act;
      current = st;
      //cerr << "GUGU " << current << ' ' << id << '\n';
      if (id < 0) {
        id = -id;
        --id;
        auto it = lines.lower_bound(id);
        if (*it != id) return false;
        if (it != lines.begin()) {
          int u = *prev(it);
          lines.erase(it);
          if (it != lines.end()) {
            int v = *it;
            if (!check(u, v))
              return false;
          }
        } else {
          lines.erase(it);
        }
      } else {
        --id;
        auto pr = lines.insert(id);
        //cerr << "HELLO " << pr.second << '\n';
        if (!pr.second)
          return false;
        auto it = pr.first;
        if (it != lines.begin() && !check(id, *prev(it)))
          return false;
        ++it;
        if (it != lines.end() && !check(id, *it))
          return false;
      }
    }
    return true;
  };

  Num l = 0, r = 1e12;
  if (pred(r)) {
    cout << "No show :(\n";
    return 0;
  }
  while ((r - l) / max((Num)1, r) > EPS) {
    Num mid = (l + r) / 2;
    if (!pred(mid))
      r = mid;
    else
      l = mid;
  }
  cout << fixed << setprecision(15) << l;

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (Num)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}