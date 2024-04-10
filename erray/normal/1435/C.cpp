// author: erray
#include<bits/stdc++.h>
 
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
  vector<int> a(6);
  for (int i = 0; i < 6; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  b.erase(unique(b.begin(), b.end()), b.end());
  n = (int) b.size();
  vector<tuple<int, int, int>> t;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 6; ++j) {
      t.emplace_back(b[i] - a[j], j, i);
    }
  }
  sort(t.begin(), t.end(), [&](auto x, auto y) {
    return make_tuple(get<0>(x), -get<1>(x), 0) > make_tuple(get<0>(y), -get<1>(y), 0);
  });
  multiset<int> act;
  for (int i = 0; i < n; ++i) {
    act.insert(b[i] - a[0]);
  }
  int ans = *prev(act.end()) - *act.begin();
  for (auto[foo, j, i] : t) {
    if (j == 5) {
      break;
    }
    act.erase(act.find(b[i] - a[j]));
    act.insert(b[i] - a[j + 1]);
    debug(i, j, act); 
    ans = min(ans, *prev(act.end()) - *act.begin()); 
  }
  cout << ans << '\n';
}