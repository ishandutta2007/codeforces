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

class dsu {
  public:
  vector<int> par, ct;
  dsu(int n) {
    par.resize(n);
    ct.resize(n, 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    ct[x] += ct[y];
    par[y] = x;
    return true;
  }
};
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  map<int, vector<int>> xPoints, yPoints;
  int cr = 0;
  for (auto[x, y] : a) {
    xPoints[x].push_back(cr);
    yPoints[y].push_back(cr);
    ++cr;    
  }

  for (auto&[foo, v] : xPoints) {
    sort(v.begin(), v.end(), [&](int x, int y) {
      return a[x].second < a[y].second;
    });  
  }

  for (auto&[foo, v] : yPoints) {
    sort(v.begin(), v.end(), [&](int x, int y) {
      return a[x].first < a[y].first;
    });  
  }

  auto check_mid = [&](int l) {
    dsu bel(n);

    vector<tuple<int, int, bool>> segs;
    for (auto&[foo, v] : xPoints) {
      for (int i = 1; i < (int) v.size(); ++i) {
        if (a[v[i]].second - a[v[i - 1]].second > l) {
          segs.emplace_back(v[i], v[i - 1], true);
        } else {
          bel.unite(v[i], v[i - 1]);
        } 
      }
    }

    for (auto&[foo, v] : yPoints) {
      for (int i = 1; i < (int) v.size(); ++i) {
        if (a[v[i]].first - a[v[i - 1]].first > l) {
          segs.emplace_back(v[i], v[i - 1], false);
        } else {
          bel.unite(v[i], v[i - 1]);
        } 
      }
    }
  
    set<int> mains;
    for (int i = 0; i < n; ++i) {
      mains.insert(bel.get(i));
    }
    debug(mains, segs);

    if ((int) mains.size() > 4) {
      return false;
    }  

    if ((int) mains.size() == 1) {
      return true;
    }
     if ((int) mains.size() == 2) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (bel.get(i) == bel.get(j)) {
            continue;
          }
          if (max(abs(a[i].first - a[j].first), abs(a[i].second - a[j].second)) <= l) {
            return true;
          }
        }
      }
      for (auto[u, v, ver] : segs) {
        if (bel.get(u) == bel.get(v)) continue;
        if (ver) {
          if (l * 2 >= abs(a[u].second - a[v].second)) {
            return true;
          }
        } else {
          if (l * 2 >= abs(a[u].first - a[v].first)) {
            return true;
          }
        
        }
      }
    } else if ((int) mains.size() <= 3) {
      for (int i = 0; i < n; ++i) {
        for (auto[v, u, ver] : segs) {
          set<int> check;
          check.insert(bel.get(i));
          check.insert(bel.get(u));
          check.insert(bel.get(v));
          if ((int) check.size() < (int) mains.size()) continue;

          //bruh
          if (ver) {
            if (max({abs(a[v].second - a[i].second), abs(a[u].second - a[i].second), abs(a[i].first - a[v].first)}) <= l) {
              debug(a[u], a[v], a[i]);
              return true;
            }
          } else {
            if (max({abs(a[v].first - a[i].first), abs(a[u].first - a[i].first), abs(a[i].second - a[v].second)}) <= l) {
              debug(a[u], a[v], a[i]);
              return true;
            }
          }                                  
        } 
      }
    } else {
      for (auto[u, v, ver] : segs) {
        for (auto[u2, v2, ver2] : segs) {
          set<int> check;
          check.insert(bel.get(u));
          check.insert(bel.get(v));
          check.insert(bel.get(u2));
          check.insert(bel.get(v2));
          if ((int) check.size() < (int) mains.size() || ver2 == ver || !ver) continue;

          pair<int, int> next = make_pair(a[u].first, a[u2].second);

          if (max({abs(next.second - a[u].second), abs(next.second - a[v].second), abs(next.first - a[u2].first), abs(next.first - a[v2].first)}) <= l) {
            return true;
          }
        }
      }
    }   
    return false;
  };

  const int inf = (int) 2e9 + 1;
  int low = 1, high = inf;
  while (low < high) {
    int mid = (0LL + low + high) >> 1;
    debug(mid);
    if (check_mid(mid)) {
      high = mid;
    } else low = mid + 1;  
  }
  
  if (low == inf) {
    return cout << -1, 0;
  }
  
  cout << low << '\n';
}