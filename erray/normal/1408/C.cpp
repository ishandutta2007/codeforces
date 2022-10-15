// author: erray
#include<bits/stdc++.h>
#undef DEBUG 

using namespace std;

template<typename T, typename F> string to_string(pair<T, F> p);
template<typename T, typename F, typename Tr> string to_string(tuple<T, F, Tr> p);
template<typename T, typename F, typename Tr, typename Th> string to_string(tuple<T, F, Tr, Th> p);
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(char c) {
  return (string) "'" + c + "'";
}
string to_string(const char* p) {
  return to_string((string) p);
}
string to_string(bool B) {
  return (B ? "true" : "false");
}
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < (int) v.size(); ++i) {
    if ((int) res.size() > 1) res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}
template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& el : v) {
    if ((int) res.size() > 1) res += ", ";
    res += to_string(el);
  }
  res += "}";
  return res;
}
template<typename T, typename F> string to_string(pair<T, F> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename T, typename F, typename Tr> string to_string(tuple<T, F, Tr> p) {
  return '(' + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ')';
}
template<typename T, typename F, typename Tr, typename Th> string to_string(tuple<T, F, Tr, Th> p) {
    return '(' + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ')';
}
void debug_out() {
  cerr << endl;
}
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" , debug_out(__VA_ARGS__)
#else
#define debug(...) (void) 37
#endif
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    auto check = [&](double x) {
      double res = 0;
      {
        double left = x;
        double cur = 0;
        double v = -1;
        for (int i = 0; i < n; ++i) {
          double cost = (a[i] - cur) / (i + 1);
          cost = min(cost, left);
          left -= cost;
          cur += cost * (i + 1);
          if (cur >= a[i]) {
            v = i;
          }
        }
        cur += (2 + v) * left;
        debug(cur);
        res += cur;
      }

      {
        double left = x;
        double cur = l;
        double v = 1;
        for (int i = n - 1; i >= 0; --i) {
          double cost = (cur - a[i]) / (n - i);
          cost = min(cost, left);
          left -= cost;
          cur -= cost * (n - i);
          if (cur <= a[i]) {
            v = i;
          }
        }
        cur -= (n - v + 1) * left;
        debug(l - cur);
        res += l - cur;
      }
      debug(x, res);
      return res > l;
    };
    int bs_ct = 100;
    double low = 0.5, high = l;
    while (bs_ct--) {
      double mid = (low + high) / 2;
      if (check(mid)) {
        high = mid;
      } else {
        low = mid;
      }
    }
    cout << setprecision(12) << fixed << low << '\n';
  }
}