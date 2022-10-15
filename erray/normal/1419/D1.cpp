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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  auto check = [&](int x) {
    vector<int> low(a.begin(), a.begin() + x);
    vector<int> high(a.begin() + x, a.end());
    reverse(low.begin(), low.end());
    high.pop_back();
    reverse(high.begin(), high.end());
    bool ok = true;
    for (int i = 0; i < (int) low.size(); ++i) {
      ok &= (low[i] < high[i]);            
    }  
    return ok;
  };
  int low = 0, high = (n - 1) / 2;
  while (high != low) {
    int mid = (low + high) / 2 + 1;
    debug(mid);
    if (check(mid)) low = mid;
    else high = mid - 1;
    debug(low, high);
  }
  cout << low << '\n';
  vector<int> lw(a.begin(), a.begin() + low);
  vector<int> hgh(a.begin() + low, a.end());
  cout << hgh.back() << ' ';
  hgh.pop_back();
  while (!lw.empty()) {
    cout << lw.back() << ' ';
    lw.pop_back();
    cout << hgh.back() << ' ';
    hgh.pop_back();
  }
  for (auto el : hgh) cout << el << ' ';

}