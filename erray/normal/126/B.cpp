// author: erray
#include<bits/stdc++.h>
 
using namespace std;

template<typename T, typename F> string to_string(pair<T, F> p);
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
  string s;
  cin >> s;
  int n = (int) s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int ind = pi[i];
    while (ind > 0 && s[i] != s[ind]) {
      ind = pi[ind - 1];
    }
    pi[i] = ind + (s[ind] == s[i]);
  }
  int ind = 0;
  int mx = 0;
  for (int i = 1; i < n - 1; ++i) {
    while (ind > 0 && s[i] != s[ind]) {
      ind = pi[ind - 1];
    }
    ind += (s[ind] == s[i]);  
    mx = max(ind, mx);
  }
  vector<unsigned long long> suf(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    suf[i] = suf[i + 1] * 27 + (s[i] - 'a' + 1);
  }
  unsigned long long cur = 0, pw = 1;
  int ans = -1;
  for (int i = 0; i < mx; ++i) {
    cur += (s[i] - 'a' + 1) * pw;
    if (cur == suf[n - i - 1]) ans = i;
    pw *= 27;
  }
  cout << (ans == -1 ? "Just a legend" : s.substr(0, ans + 1)) << '\n';
}