// author: erray
#undef DEBUG 
#include <bits/stdc++.h>
 
using namespace std;
template<typename A, typename B> string to_string(const pair<A, B>& p);
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t);
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char& c) {
  return string("'") + c + "'";
}

string to_string(const char *c) {
  return to_string(string(c));
}

string to_string(const bool& b) {
  return (b ? "true" : "false");
}

string to_string(const vector<bool>& v) {
  string res = "{";
  for (int i = 0; i < (int) v.size(); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<size_t T> string to_string(const bitset<T>& bs) {
  return bs.to_string();
}

template<typename T> string to_string(queue<T> q) {
  string res = "{";
  size_t sz = q.size();
  while (sz--) {
    T cur = q.front();
    q.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T, class C> string to_string(priority_queue<T, vector<T>, C> pq) {
  string res = "{";
  while (!pq.empty()) {
    T cur = pq.top();
    pq.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(const T& v) {
  string res = "{";
  for (auto &el : v) {
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(el);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(const pair<A, B>& p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ')';
}
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ')';
}

void debug_out(int size, bool first, string name) {
  vector<string> tmp = {name};
  vector<int> tmp2 = {size, first};
  cerr << endl;
}

constexpr int buffer_size = 255;

template<typename Head, typename... Tail> void debug_out(int size, bool first, string name, Head H, Tail... T) {
  string tmp;
  int off = 0;
  while ((!name.empty() && name[0] != ',') || off != 0) {
    tmp += name[0];
    name.erase(name.begin());
    char c = tmp.back();
    if (c == '{' || c == '(') {
      ++off;
    } else if (c == '}' || c == ')'){
      --off;
    }
  }
  if (!name.empty()) {
    name.erase(name.begin());
  }
  if (tmp[0] == ' ') {
    tmp.erase(tmp.begin());
  }

  string buff = to_string(H);
  if ((int) buff.size() + size + (int) tmp.size() > buffer_size - 5 && !first) {
    cerr << '\n';
    size = 0;
  }
  cerr << '[' << tmp << ": " << buff << "] ";
  debug_out(((int) buff.size() + size + (int) tmp.size() + 5) % buffer_size, false, name, T...);
}

#ifdef DEBUG
#define debug(...) cerr << "-> ", debug_out(3, true, string(#__VA_ARGS__), __VA_ARGS__)
#define here cerr << "-> " << __LINE__ << endl
#else
#define debug(...) void(37)
#define here void(37)
#endif
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  #ifdef LOCAL  
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
  #endif
  vector<int> OR(n);
  vector<int> AND(n);  
  int ph;
  int aor = INT_MAX;
  for (int i = 1; i < n; ++i) {
    cout << "or " << 1 << ' ' << (i + 1) << endl;
    #ifdef LOCAL
    OR[i] = a[0] | a[i];
    #else
    cin >> OR[i];
    #endif
    aor &= OR[i];
  }
  
  for (int i = 1; i < n; ++i) {
    cout << "and " << 1 << ' ' << i + 1 << endl;
    #ifdef LOCAL      
    AND[i] = a[0] & a[i];  
    #else 
    cin >> AND[i];
    #endif
  }  

  cout << "or " << 2 << ' ' << 3 << endl;
  #ifdef LOCAL
  ph = a[1] | a[2];
  #else
  cin >> ph;
  #endif
  vector<int> ans(n);
  for (int b = 29; b >= 0; --b) {
    int add = (1 << b);
    for (int i = 1; i < n; ++i) {
      if (AND[i] & add) {
        ans[0] |= add;
        break;
      }
    }

    debug(((aor >> b) & 1), (((ph >> b) & 1) == 0));
    if (((aor >> b) & 1) && (((ph >> b) & 1) == 0)) {
      ans[0] |= add;  
    }

    if (((ans[0] >> b) & 1) != ((a[0] >> b) & 1)) {
    debug((ans[0] >> b) & 1, (a[0] >> b) & 1);  
      for (int i = 0; i < n; ++i) {
        debug(i, (a[i] >> b) & 1);
      }      
    }

    for (int i = 1; i < n; ++i) {
      if ((AND[i] & add) || ((OR[i] & add) && (ans[0] & add) == 0)) {
        ans[i] |= add;
      } 
    }
  }
    debug(a, ans);

  #ifdef LOCAL
    assert(a == ans);
  #endif
  
  sort(ans.begin(), ans.end());
  cout << "finish " << ans[k - 1] << endl;
}