/*
 * author:  ADMathNoob
 * created: 08/29/21 10:35:21
 * problem: https://codeforces.com/contest/1556/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

// can't have namespaces, else to_string(int) is hidden, for example

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

// print an empty line
void debug_out() {
#ifdef _DEBUG
  cerr << endl;
#endif
}

// can't call debug with no arguments
#ifdef _DEBUG
#define debug(...)                    \
  cerr << "" << #__VA_ARGS__ << ": "; \
  debug_better(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 1) {
    a.pop_back();
    --n;
  }
  vector<long long> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i];
    if (i % 2 == 0) {
      pref[i + 1] += a[i];
    } else {
      pref[i + 1] -= a[i];
    }
  }
  debug(a);
  long long ans = 0;
  for (int i = 0; i < n; i += 2) {
    long long mn = 0;
    for (int j = i + 1; j < n; j += 2) {
      if (j == i + 1) {
        ans += min(a[i], a[j]);
      } else {
        long long mid = pref[j] - pref[i + 1];
        long long needL = -mn;
        debug(needL, mid);
        assert(needL + mid > 0);
        long long needR = needL + mid;
        long long haveL = a[i] - needL;
        long long haveR = a[j] - needR;
        if (haveL >= 0 && haveR >= 0) {
          ans += min(haveL, haveR) + 1;
        }
      }
      mn = min(mn, pref[j + 1] - pref[i + 1]);
    }
  }
  cout << ans << '\n';
  return 0;
}