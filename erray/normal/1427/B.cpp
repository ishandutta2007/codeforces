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
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<pair<int, int>> ord;
    bool first = true;
    int add = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') {
        if (first) {
          debug(i);
          first = false;
        } else {
          ord.emplace_back(add, i);        
        }
        add = 0;              
      } else {
        ++add;
      }
    }
    sort(ord.begin(), ord.end());
    for (auto[val, ind] : ord) {
      --ind;
      while (k > 0 && s[ind] == 'L') {
        debug(ind);
        --k;
        s[ind] = 'W';
        --ind;
      }
    }
    debug(s);

    vector<int> exs;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'W') {
        exs.push_back(i);
      }
    }
    if (exs.empty()) {
      cout << max(0, k * 2 - 1) << '\n';
      continue;
    }
    int low = exs.front() - 1;
    int high = exs.back() + 1;
    while (low >= 0 && k > 0) {
      s[low] = 'W';
      --low;
      --k;
    }
    while (high < n && k > 0) {
      s[high] = 'W';
      ++high;
      --k;    
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L') {
        continue;
      }
      if (i > 0 && s[i - 1] == 'W') {
        ++ans;
      }
      ++ans;
    }
    debug(s);
    cout << ans << '\n';
  }
}