/*
 * author:  ADMathNoob
 * created: 12/18/21 10:35:21
 * problem: https://codeforces.com/contest/1620/problem/E
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

const int N = 500000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  vector<int> a; // node
  vector<int> rep(N, -1); // node representing the label i
  vector<int> p;
  vector<int> value;
  auto Get = [&](int x) {
    if (rep[x] != -1) {
      return rep[x];
    }
    int id = (int) p.size();
    p.push_back(-1);
    value.push_back(x);
    rep[x] = id;
    return id;
  };
  vector<int> order;
  while (tt--) {
    int op, x;
    cin >> op >> x;
    --x;
    int vx = Get(x);
    if (op == 1) {
      debug(op, x);
      a.push_back(vx);
    }
    if (op == 2) {
      int y;
      cin >> y;
      --y;
      debug(op, x, y);
      if (x != y) {
        int vy = Get(y);
        p[vx] = vy;
        order.push_back(vx);
        rep[value[vx]] = -1;
      }
    }
    debug(a);
    debug(p);
    debug(value);
    // debug(rep);
    debug_out();
  }
  debug(order);
  reverse(order.begin(), order.end());
  for (int i : order) {
    value[i] = value[p[i]];
  }
  for (int i = 0; i < (int) a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << value[a[i]] + 1;
  }
  cout << '\n';
  return 0;
}