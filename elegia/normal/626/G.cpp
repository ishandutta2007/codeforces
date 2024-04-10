#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <tuple>
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

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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

struct Frac {
  ll a, b;

  Frac(ll a = 0, ll b = 1) : a(a), b(b) {}

  Frac operator+(const Frac& rhs) const { return Frac(a * rhs.b + b * rhs.a, b * rhs.b); }
  Frac operator-() const { return Frac(-a, b); }
  Frac operator-(const Frac& rhs) const { return *this + (-rhs); }

  bool operator<(const Frac& rhs) const { return a * rhs.b < b * rhs.a; }
  bool operator>(const Frac& rhs) const { return a * rhs.b > b * rhs.a; }

  operator double() const { return (double)a / b; }
};

const int N = 200010;

int n, t, q;
double ans;
int p[N], l[N], k[N];
set<pair<Frac, int>, greater<pair<Frac, int>>> front;
set<pair<Frac, int>> back;

Frac get(int p, int l, int k) {
  return Frac(p * (k + 1), l + k + 1) - Frac(p * k, l + k);
}

int main() {
  scanf("%d%d%d", &n, &t, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &l[i]);
  for (int i = 1; i <= n; ++i) front.insert(make_pair(Frac(p[i], l[i] + 1), i));
  while (q--) {
    int opt, r;
    scanf("%d%d", &opt, &r);
    ans -= p[r] * (double)k[r] / (k[r] + l[r]);
    if (k[r] < l[r])
      front.erase(make_pair(get(p[r], l[r], k[r]), r));
    if (k[r])
      back.erase(make_pair(get(p[r], l[r], k[r] - 1), r));
    if (opt == 1) ++l[r];
    else {
      --l[r];
      if (k[r] > l[r]) {
        --k[r];
        ++t;
      }
    }
    ans += p[r] * (double)k[r] / (k[r] + l[r]);
    if (k[r] < l[r])
      front.insert(make_pair(get(p[r], l[r], k[r]), r));
    if (k[r])
      back.insert(make_pair(get(p[r], l[r], k[r] - 1), r));

    while (!back.empty() && !front.empty() && back.begin()->first < front.begin()->first) {
      ans += front.begin()->first;
      ans -= back.begin()->first;
      int j = back.begin()->second, i = front.begin()->second;
      front.erase(front.begin());
      back.erase(back.begin());

      back.erase(make_pair(get(p[i], l[i], k[i] - 1), i));
      front.erase(make_pair(get(p[j], l[j], k[j]), j));

      ++k[i];
      if (k[i] < l[i]) front.insert(make_pair(get(p[i], l[i], k[i]), i));
      back.insert(make_pair(get(p[i], l[i], k[i] - 1), i));

      --k[j];
      front.insert(make_pair(get(p[j], l[j], k[j]), j));
      if (k[j]) back.insert(make_pair(get(p[j], l[j], k[j] - 1), j));
    }

    while (t && !front.empty()) {
      --t;
      ans += front.begin()->first;
      int i = front.begin()->second;
      front.erase(front.begin());
      back.erase(make_pair(get(p[i], l[i], k[i] - 1), i));
      ++k[i];
      if (k[i] < l[i]) front.insert(make_pair(get(p[i], l[i], k[i]), i));
      back.insert(make_pair(get(p[i], l[i], k[i] - 1), i));
    }

    printf("%.9f\n", ans);
  }
  return 0;
}