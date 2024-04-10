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


  int stt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1) {
      ++stt;
    }
    if (a[i] >= 2) {
      break;
    }
  }

  auto imp = [&] {
    cout << -1 << '\n';
    exit(0);
  };

  vector<pair<int, int>> ans;
  int lst = -1;
  int cur = n - 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] != 3) {
      continue;
    }
    ans.emplace_back(i, cur);
    if (lst != -1) {
      ans.emplace_back(i, cur + 1);
    }
    lst = i;
    --cur;
  }
                           
  debug(ans);

  int take = -1;
  for (int i = lst + 1; i < n; ++i) {
    if (a[i] == 2) {
      take = i;
      break;
    }
  }

  if (lst != -1) {
    if (take != -1) {
      ans.emplace_back(take, cur + 1);
    } else {
      if (count(a.begin(), a.end(), 2) >= count(a.begin(), a.end(), 1) - stt) {
        imp();  
      }
      for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 1) {
          if (i < lst) {
            imp();
          }
          ans.emplace_back(i, cur + 1);
          break;
        }
      }
    }
  }

  vector<int> st;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 2) {
      st.push_back(cur);
      ans.emplace_back(i, cur);
      --cur;
    } else if (a[i] == 1) {
      if (st.empty()) {
        ans.emplace_back(i, cur);
        --cur;
      } else {
        int ind = st.back();
        st.pop_back();
        ans.emplace_back(i, ind);
      }
    }
  }

  if (!st.empty()) {
    imp();
  }

  cout << (int) ans.size() << '\n';
  for (auto[l, r]  : ans) {
    cout << n - r << ' ' << l + 1 << '\n';
  }
}