/*
 * author:  ADMathNoob
 * created: 01/03/22 09:35:42
 * problem: https://codeforces.com/contest/1621/problem/E
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
#define debug(...)                      \
  do {                                  \
    cerr << "" << #__VA_ARGS__ << ": "; \
    debug_better(__VA_ARGS__);          \
  } while (false)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    a.resize(m);
    reverse(a.begin(), a.end());
    vector<int> k(m);
    vector<vector<int>> b(m);
    vector<long long> sum(m);
    for (int i = 0; i < m; i++) {
      cin >> k[i];
      b[i].resize(k[i]);
      for (int j = 0; j < k[i]; j++) {
        cin >> b[i][j];
        sum[i] += b[i][j];
      }
    }
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return sum[i] * k[j] < sum[j] * k[i];
    });
    vector<int> pos(m);
    for (int i = 0; i < m; i++) {
      pos[order[i]] = i;
    }
    vector<int> ok(m);
    vector<int> okL(m);
    vector<int> okR(m);
    vector<int> pref_ok(m + 1);
    vector<int> pref_okL(m + 1);
    vector<int> pref_okR(m + 1);
    for (int i = 0; i < m; i++) {
      ok[i] = (sum[order[i]] <= k[order[i]] * a[i]);
      okL[i] = (i > 0 && sum[order[i]] <= k[order[i]] * a[i - 1]);
      okR[i] = (i < m - 1 && sum[order[i]] <= k[order[i]] * a[i + 1]);
      pref_ok[i + 1] = pref_ok[i] + ok[i];
      pref_okL[i + 1] = pref_okL[i] + okL[i];
      pref_okR[i + 1] = pref_okR[i] + okR[i];
    }
    debug(ok, okL, okR);
    auto AllOk = [&](const vector<int>& okk, int L, int R) {
      return (okk[R + 1] - okk[L] == R - L + 1);
    };
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < k[i]; j++) {
        long long new_sum = sum[i] - b[i][j];
        int new_k = k[i] - 1;
        int low = 0, high = m;
        while (low < high) {
          int mid = (low + high) / 2;
          if (new_sum <= new_k * a[mid]) {
            high = mid;
          } else {
            low = mid + 1;
          }
        }
        if (low == m) {
          cout << 0;
          continue;
        }
        assert(new_sum <= new_k * a[low]);
        bool res = true;
        if (low >= pos[i]) {
          // move this one right
          res &= AllOk(pref_ok, 0, pos[i] - 1);
          res &= AllOk(pref_okL, pos[i] + 1, low);
          res &= AllOk(pref_ok, low + 1, m - 1);
        } else {
          res &= AllOk(pref_ok, 0, low - 1);
          res &= AllOk(pref_okR, low, pos[i] - 1);
          res &= AllOk(pref_ok, pos[i] + 1, m - 1);
        }
        cout << res;
      }
    }
    cout << '\n';
  }
  return 0;
}