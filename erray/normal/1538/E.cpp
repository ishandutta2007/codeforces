// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 template<typename A, typename B> string to_string(pair<A, B> p);
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t);
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t);

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(char c) {
  return string("'") + c + "'";
}

string to_string(const char* c) {
  return to_string(string(c));
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}

string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < int(v.size()); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& e : v) {
    if (int(res.size()) > 1) {
      res += ", ";
    }
    res += to_string(e);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(pair<A, B> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + '}';
}
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + '}';
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << "  " << to_string(H);
  debug_out(T...);
}

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(37)
#endif
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto Count = [&](string s) {
      debug(s);
      int res = 0;
      for (int i = 0; i + 3 < int(s.size()); ++i) {
        res += s.substr(i, 4) == "haha";
      }
      return res;
    };

    using el = pair<long long, string>;
    auto Unite = [&](el x, el y) {
      debug(x, y);
      el res;
      res.second = x.second + y.second;
      if (int(res.second.size()) > 6) {
        res.second.erase(res.second.begin() + 3, res.second.end() - 3);
      }

      int xsize = min(3, int(x.second.size()));
      int ysize = min(3, int(y.second.size()));
      res.first = x.first + y.first + Count(x.second.substr(int(x.second.size()) - xsize) + y.second.substr(0, ysize));
      debug(res);
      return res;
    };

    map<string, el> mp;
    string lst;
    for (int i = 0; i < n; ++i) {
      string var, op;
      cin >> var >> op;
      if (op == "=") {
        string x, y, foo;
        cin >> x >> foo >> y;
        mp[var] = Unite(mp[x], mp[y]);  
      } else {
        string val;
        cin >> val;
        mp[var] = {Count(val), val};
      }
      lst = var;
    }
    cout << mp[lst].first << '\n';
  }
}