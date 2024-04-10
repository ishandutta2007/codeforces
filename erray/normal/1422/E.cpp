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
  string s;
  cin >> s;
  int n = (int) s.size();
  string cur;
  vector<int> sz(n);
  vector<string> ans(n);
  vector<int> inds;
  vector<char> hold(256);
  auto check = [&] {
    int len = (int) cur.size() - 1;
    if ((int) cur.size() >= 3) {
      return cur[len] == cur[len - 1] && hold[cur[len]] < cur[len] && inds[len] == inds[len - 1] - 1; 
    } else if ((int) cur.size() == 2) {
      return cur[len] == cur[len - 1] && inds[len] == inds[len - 1] - 1;
    }
    return false;
  };
  for (int i = n - 1; i >= 0; --i) {
    if (!cur.empty() && cur.back() != s[i]) {
      hold[s[i]] = cur.back();
    }
    cur += s[i];
    inds.push_back(i);
    while (check()) {
      cur.pop_back();
      cur.pop_back();
      inds.pop_back();
      inds.pop_back();    
    }
    debug(cur, inds, hold[s[i]]);  
    sz[i] = (int) cur.size();
    if ((int) cur.size() > 10) {
      for (int j = 0; j < 5; ++j) {
        ans[i] += cur[(int) cur.size() - j - 1];
      }
      ans[i] += "..."s + cur[1] + cur[0];
    } else {
      reverse(cur.begin(), cur.end());
      ans[i] = cur;
      reverse(cur.begin(), cur.end());
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << sz[i] << ' ' << ans[i] << '\n';
  }
}