/*
 * author:  ADMathNoob
 * created: 07/17/21 10:32:13
 * problem: https://codeforces.com/contest/1530/problem/E
 */

/*
g++ 1530E.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1530E.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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

template <typename T>
vector<int> table(int m, const T& w) {
  // p[i] is the length of the longest substring of w ending at index i
  // which is also a prefix of w
  // the variable names 'm' and 'w' are chosen to reflect that this
  // function should be called on the search word, NOT the text
  // (fail from Codeforces 1466G)
  vector<int> p(m, 0);
  int k = 0;
  for (int i = 1; i < m; i++) {
    while (k > 0 && !(w[i] == w[k])) {
      k = p[k - 1];
    }
    if (w[i] == w[k]) {
      k++;
    }
    p[i] = k;
  }
  return p;
}

template <typename T>
vector<int> table(const T& s) {
  return table((int) s.size(), s);
}

template <typename T>
vector<int> search(int n, const T& s, int m, const T& w, const vector<int>& p) {
  assert(m > 0);
  vector<int> res;
  int k = 0;
  for (int i = 0; i < n; i++) {
    while (k == m || (k > 0 && !(s[i] == w[k]))) {
      k = p[k - 1];
    }
    if (s[i] == w[k]) {
      k++;
    }
    if (k == m) {
      res.push_back(i - m + 1);
    }
  }
  return res;  // returns 0-indexed positions of w in s
}

template <typename T>
vector<int> search(const T& s, const T& w, const vector<int>& p) {
  return search((int) s.size(), s, (int) w.size(), w, p);
}

template <typename T>
vector<int> search(const T& s, const T& w) {
  return search(s, w, table(w));
}

string Solve(string s) {
  sort(s.begin(), s.end());
  int n = (int) s.size();
  string all = s;
  all.resize(unique(all.begin(), all.end()) - all.begin());
  int A = (int) all.size();
  if (A == 1 || A == n) {
    return s;
  }
  vector<int> ccnt(26);
  for (char c : s) {
    ++ccnt[c - 'a'];
  }
  for (int a = 0; a < 26; a++) {
    if (ccnt[a] == 1) {
      char f = 'a' + a;
      string t = string(1, f);
      for (char c : s) {
        if (c != f) {
          t += c;
        }
      }
      return t;
    }
  }
  // f(t) has to be 1
  char mn = all[0];
  char mn2 = all[1];
  int cnt = count(s.begin(), s.end(), mn);
  if (cnt <= 2) {
    return s;
  }
  if (cnt - 1 <= ((n - 1) + 1) / 2) {
    // can start with 2 'a's
    string t = string(2, mn);
    cnt -= 2;
    int at = (int) (find(s.begin(), s.end(), mn2) - s.begin());
    for (int it = 0; it < cnt; it++) {
      t += s[at++];
      t += mn;
    }
    t += s.substr(at);
    return t;
  }
  if (A == 2) {
    // the only choice is abbbbbbbaaaaaaaaa, else there is
    // the substring ab somewhere
    sort(s.rbegin(), s.rend() - 1);
    return s;
  } else {
    // abaaaaaaacbbbb(rest)
    assert(A >= 3);
    int cnt2 = count(s.begin(), s.end(), mn2);
    string t = string(1, mn);
    t += mn2;
    t += string(cnt - 1, mn);
    t += all[2];
    t += string(cnt2 - 1, mn2);
    t += s.substr(cnt + cnt2 + 1);
    return t;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    string ans = Solve(s);
    auto t = table(ans);
    int mx = *max_element(t.begin(), t.end());
    int n = (int) s.size();
    assert(mx == n - 1 || mx == 0 || mx == 1);
    cout << ans << '\n';
  }
  return 0;
}