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
  int n, m;
  cin >> n >> m;
  vector<int> l(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }
  sort(l.begin(), l.end());
  multiset<int> a(l.begin(), l.end());
  multiset<int> dist;  
  for (int i = 1; i < n; ++i) {
    dist.insert(l[i] - l[i - 1]);  
  }

  auto Find = [&] {
    debug(a, dist);
    if ((int) a.size() <= 1) {
      return 0;      
    }
    return (*prev(a.end()) - *a.begin()) - *prev(dist.end());
  };
  auto Add = [&](int x) {
    if (a.empty()) {
      a.insert(x);
      return;
    }
    auto it = a.lower_bound(x);
    int ct = 0;
    if (it != a.end()) {
      dist.insert(*it - x);
      ++ct;
    }
    if (it != a.begin()) {
      dist.insert(x - *prev(it));
      ++ct;
    }
    if (ct == 2) {
      dist.erase(dist.find(*it - *prev(it)));
    }
    a.insert(x);
  };
  auto Erase = [&](int x) {
    auto it = a.lower_bound(x);
    int ct = 0;
    if (it != a.begin()) {
      dist.erase(dist.find(x - *prev(it)));
      ++ct;
    }
    if (it != prev(a.end())) {
      dist.erase(dist.find(*next(it) - x));      
      ++ct;
    }  
    if (ct == 2) {
      dist.insert(*next(it) - *prev(it));
    }
    a.erase(a.find(x));
  };
  cout << Find() << '\n';
  while (m--) {
    int type, v;
    cin >> type >> v;
    if (type) {
      Add(v);
    } else {
      Erase(v);
    }
    cout << Find() << '\n';
  }
}