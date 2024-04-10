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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }
  vector<int> big_dp(k, -1);
  big_dp[0] = 0;
  for (int q = 0; q < n; ++q) {
    vector<int> new_big_dp(k, -1);
    new_big_dp[0] = 0;
    vector<int> dp(75 * 75, -1);
    dp[0] = 0;
    for (auto el : mat[q]) {
      for (int j = 75 * 75 - el - 1; j >= 0; --j) {
        if (dp[j] != -1) {
          if (dp[j + el] == -1) {
            dp[j + el] = dp[j] + 1;          
          } else {
            dp[j + el] = min(dp[j + el], dp[j] + 1);
          }
        } 
      }
    }

    vector<int> helper(k, -1);
    for (int i = 0; i < 75 * 75; ++i) {
      if (dp[i] <= m / 2 && dp[i] != -1) {
        helper[i % k] = i;
      } 
    }
    debug(helper);
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        if (helper[j] != -1 && big_dp[i] != -1) {
          new_big_dp[(i + j) % k] = max(new_big_dp[(i + j) % k], big_dp[i] + helper[j]);
        }   
      }
    }
    swap(new_big_dp, big_dp);
  }
  cout << big_dp[0] << '\n'; 
}