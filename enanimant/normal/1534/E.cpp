/*
 * author:  ADMathNoob
 * created: 06/13/21 13:03:54
 * problem: https://codeforces.com/contest/1534/problem/E
 */

/*
g++ 1534E.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1534E.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
  cerr << "[" << #__VA_ARGS__ << "]: "; \
  debug_better(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 505;

int Ask(const vector<int>& is) {
  cout << "?";
  for (int i : is) {
    cout << ' ' << i + 1;
  }
  cout << endl;
  int r;
  cin >> r;
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<bool>> dp(N, vector<bool>(n + 1, false));
  vector<vector<int>> last(N, vector<int>(n + 1, -1));
  dp[0][n] = true;
  for (int m = 0; m + 1 < N; m++) {
    for (int z = 0; z <= n; z++) {
      if (!dp[m][z]) {
        continue;
      }
      for (int m01 = 0; m01 <= k; m01++) {
        int m10 = k - m01;
        if (m01 > z || m10 > n - z) {
          continue;
        }
        int new_z = z + (m10 - m01);
        // debug(m, z, m01, m10, new_z);
        assert(0 <= new_z && new_z <= n);
        dp[m + 1][new_z] = true;
        last[m + 1][new_z] = m01;
      }
    }
  }
  vector<int> cnts;
  for (int m = 0; m < N; m++) {
    if (dp[m][0]) {
      int z = 0;
      for (int j = m; j > 0; j--) {
        int m01 = last[j][z];
        int m10 = k - m01;
        int last_z = z - (m10 - m01);
        cnts.push_back(m01);
        z = last_z;
      }
      reverse(cnts.begin(), cnts.end());
      assert(cnts[0] == k);
      debug(cnts);
      vector<int> cur(n, 0);
      int ans = 0;
      for (int it = 0; it < m; it++) {
        vector<int> rem = {cnts[it], k - cnts[it]};
        vector<int> is;
        for (int i = 0; i < n; i++) {
          if (rem[cur[i]] > 0) {
            rem[cur[i]] -= 1;
            cur[i] ^= 1;
            is.push_back(i);
          }
        }
        ans ^= Ask(is);
      }
      cout << "! " << ans << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}