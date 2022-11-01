/*
 * author:  ADMathNoob
 * created: 03/21/21 09:12:46
 * problem: https://codeforces.com/contest/1483/problem/B
 */

/*
g++ 1483B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors && a
g++ 1483B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors -ggdb && gdb a
g++ 1483B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors && a


*/

#include "bits/stdc++.h"

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(const char c) {
  string s = "'";
  s += c;
  s += "'";
  return s;
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < (int) v.size(); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  // cerr << v << '\n';
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_commas() {
}

template <typename Head, typename... Tail>
void debug_commas(Head H, Tail... T) {
  // comma before each element
  cerr << ", " << to_string(H);
  debug_commas(T...);
}

template <typename Head, typename... Tail>
void debug_better(Head H, Tail... T) {
  cerr << "[" << to_string(H);
  debug_commas(T...);
  cerr << "]" << endl;
}

// can't call debug with no arguments
#ifdef _DEBUG
#define debug(...)                      \
  cerr << "[" << #__VA_ARGS__ << "]: "; \
  debug_better(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> nxt(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
      nxt[i] = (i + 1) % n;
      if (__gcd(a[i], a[nxt[i]]) == 1) {
        s.insert(i);
      }
    }
    vector<int> res;
    int pos = 0;
    vector<bool> removed(n, false);
    while (!s.empty()) {
      auto it = s.lower_bound(pos);
      if (it == s.end()) {
        it = s.begin();
      }
      int i = *it;
      s.erase(it);
      debug(pos);

      int r = nxt[i];
      removed[r] = true;
      res.push_back(r);
      if (s.count(r)) {
        s.erase(r);
      }

      nxt[i] = nxt[r];
      if (!removed[nxt[i]] && __gcd(a[i], a[nxt[i]]) == 1) {
        s.insert(i);
      }
      pos = (r + 1) % n;
    }

    cout << res.size();
    for (int i = 0; i < (int) res.size(); i++) {
      cout << ' ' << res[i] + 1;
    }
    cout << '\n';
  }

  return 0;
}