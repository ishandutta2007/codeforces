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

namespace sieve {
  vector<int> list(int n) {
    assert(n >= 0);
    if (n == 0) return vector<int>(0);
    vector<int> res;
    vector<bool> ip(n + 1, true);
    for (int i = 2; i <= n; ++i) {
      if (!ip[i]) continue;
      res.push_back(i);
      if ((int) ceil(1.0 * n / i) < i) continue;
      for (int j = i * i; j <= n; j += i) {
        ip[j] = false;
      }
    }
    return res;
  }
  vector<bool> check(int n) {
    assert(n >= 0);
    if (n == 0) return vector<bool>(1, false);
    vector<int> res;
    vector<bool> ip(n + 1, true);
    for (int i = 2; i <= n; ++i) {
      if (!ip[i]) continue;
      res.push_back(i);
      if (ceil(1.0 * n / i) < i) continue;
      for (int j = i * i; j <= n; j += i) {
        ip[j] = false;
      }
    }
    ip[0] = false;
    if (n > 1) ip[1] = false;
    return ip;
  }
}

namespace divs {
  vector<int> check_primes;
  void createSieve(long long limit) {
    check_primes = sieve::list((int) ceil(sqrt(limit)));  
  }
  vector<pair<long long, int>> prime(long long n, bool fast = false) {
    assert(n > 0);
    vector<pair<long long, int>> res;
    if (!fast) {
      for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) res.emplace_back(i, 0);
        while (n % i == 0) {
          n /= i;
          ++res.back().second;
        }
      }
    } else {
      assert(!check_primes.empty());
      for (int i = 0; i < (int) check_primes.size() && 1LL * check_primes[i] * check_primes[i] <= n; ++i) {
        if (n % check_primes[i] == 0) res.emplace_back(check_primes[i], 0);
        while (n % check_primes[i] == 0) {
          n /= check_primes[i];
          ++res.back().second;
        }
      }
    }
    if (n > 1) res.emplace_back(n, 1);
    return res;
  }
  vector<long long> all(long long n) {
    assert(n > 0);
    vector<long long> res;
    for (long long i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        res.push_back(i);
        res.push_back(n / i);
      }      
    }
    if ((int) res.size() > 2 && res.back() == res[(int) res.size() - 2]) res.pop_back();
    return res;
  }
} 



const int N = sqrt((int) 1e9 + 1) + 1;

#define int long long  

int32_t main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;         
    int tn = n;
    divs::createSieve((int) 1e9);
    auto divs = divs::prime(n, true);
    n = tn;
    if ((int) divs.size() == 1) {
      int cur = divs[0].first;
      while (divs[0].second-- > 0) {
        cout << cur << ' ';
        cur *= divs[0].first;
      }
      cout << '\n' << 0 << '\n';
      continue;
    }
    if ((int) divs.size() == 2 && divs[0].second == 1 && divs[1].second == 1) {
      cout << divs[0].first << ' ' << divs[1].first << ' ' << divs[0].first * divs[1].first << '\n';
      cout << 1 << '\n';            
    } else {
      vector<int> ans;
      map<int, int> vis;
      auto add = [&](int x) {
        if (vis[x]) return;
        vis[x] = true;
        ans.push_back(x);
      };
      if ((int) divs.size() != 2) {
        for (int i = 0; i < n; ++i) {
          int bef = divs[(i ? i - 1 : (int) divs.size() - 1)].first;  
          add(bef * divs[i].first);          
          if (i < (int) divs.size() - 1) vis[divs[i].first * divs[i + 1].first] = true;
          int sy = divs[i].second;
          while (sy--) {
            n /= divs[i].first;
          }
          sy = divs[i].second;
          auto tmp = divs::all(n);
          int curt = divs[i].first;
          for (int j = 0; j < sy; ++j) {
            for (auto el : tmp) {
              add(el * curt);
            }                              
            if (j < sy - 1) curt *= divs[i].first;          
          }   
          if (i < (int) divs.size() - 1) vis[divs[i].first * divs[i + 1].first] = false;

        }
      } else {
        for (int i = 0; i < n; ++i) {
          int bef = divs[(i ? i - 1 : (int) divs.size() - 1)].first;  
          add(bef * divs[i].first * (i == 0 ? (divs[i].second > 1 ? divs[i].first : divs[i ^ 1].first) : 1));          
          if (i < (int) divs.size() - 1) vis[divs[i].first * divs[i + 1].first] = true;
          int sy = divs[i].second;
          while (sy--) {
            n /= divs[i].first;
          }
          sy = divs[i].second;
          auto tmp = divs::all(n);
          int curt = divs[i].first;
          for (int j = 0; j < sy; ++j) {
            for (auto el : tmp) {
              add(el * curt);
            }                              
            if (j < sy - 1) curt *= divs[i].first;          
          }   
          if (i < (int) divs.size() - 1) vis[divs[i].first * divs[i + 1].first] = false;

        }
      }
      add(divs[0].first * divs.back().first);
      for (auto el : ans) cout << el << ' '; 
      cout << '\n';
      cout << 0 << '\n';
    }
  }
}