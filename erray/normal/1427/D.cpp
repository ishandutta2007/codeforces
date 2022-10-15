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
    --a[i];
  }
  vector<vector<int>> ans;

  while (!is_sorted(a.begin(), a.end())) {
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
      pos[a[i]] = i;
    }
    int ch = 0;
    for (int i = 1; i < n; ++i) {
      if (pos[i] < pos[i - 1]) {
        ch = i;
      }
    }

    int l = pos[ch], r = pos[ch - 1];
    vector<int> new_a;
    vector<int> add;
    vector<int> can;
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[i - 1] + 1) {
        can.push_back(i);
      }
    }
    // l = p[i][0], r = p[i + 1][lst]
    if (l > 0) {
      add.push_back(l);
    }
    int ps = *lower_bound(can.begin(), can.end(), l + 1);
    assert(ps <= r);

    add.push_back(ps - l);
    add.push_back(r - ps + 1);
    
    if (r < n - 1) {
      add.push_back(n - 1 - r);
    }
    
    assert(accumulate(add.begin(), add.end(), 0) == n);
    ans.push_back(add);

    vector<vector<int>> div((int) add.size());
    int p = 0;

    for (int i = 0; i < n; ++i) {
      if (add[p] == 0) {
        ++p;
      }
      --add[p];
      div[p].push_back(a[i]);
    }
    reverse(div.begin(), div.end());
    for (auto vv : div) {
      for (auto el : vv) {
        new_a.push_back(el);
      }
    }
    swap(new_a, a);
    debug(a);
  }
  assert((int) ans.size() <= n);
  
  cout << (int) ans.size() << '\n';
  for (auto el : ans) {
    cout << (int) el.size() << '\n';
    for (auto e : el) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}