#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

int get_col_win(ll s, ll e) {
  vector <ll> go;
  {
    ll ce = e;
    while (ce >= s) {
      go.push_back(ce);
      ce /= 2;
    }
    reverse(go.begin(), go.end());
  }
  {
    int lst = 0;
    bool stable = false;
    for (int i = (int)go.size() - 2; i >= 0; --i) {
      int f, s;
      if (!stable) {
        f = lst ^ ((go[i + 1] - (go[i] + 1)) % 2);
        s = lst ^ ((go[i + 1] - 2 * go[i]) % 2);
      } else {
        f = lst;
        s = lst;
      }
      if (f == 0 || s == 0) lst = 1;
      else lst = 0;
      if (s == 0) stable = true;
      else stable = false;
      //cout << go[i] << ' ' << f << ' ' << s << ' ' << lst << ' ' << stable << endl; 
    }
    int col;
    if (!stable) {
      col = lst ^ ((go[0] - s) % 2);
    } else {
      col = lst;
    }
    return col;
  }
}



int get_col_lose(ll s, ll e) {
  vector <ll> go;
  {
    ll ce = e;
    while (ce >= s) {
      go.push_back(ce);
      ce /= 2;
    }
    reverse(go.begin(), go.end());
  }
  {
    int lst = 1;
    bool stable = true;
    for (int i = (int)go.size() - 2; i >= 0; --i) {
      int f, s;
      if (!stable) {
        f = lst ^ ((go[i + 1] - (go[i] + 1)) % 2);
        s = lst ^ ((go[i + 1] - 2 * go[i]) % 2);
      } else {
        f = lst;
        s = lst;
      }
      if (f == 0 || s == 0) lst = 1;
      else lst = 0;
      if (s == 0) stable = true;
      else stable = false;
      //cout << go[i] << ' ' << f << ' ' << s << ' ' << lst << ' ' << stable << endl; 
    }
    int col;
    if (!stable) {
      col = lst ^ ((go[0] - s) % 2);
    } else {
      col = lst;
    }
    return col;
  }
}


vector <vector <int>> get(ll s, ll e) {
  vector <vector <int>> ret(2, vector <int> (2));
  vector <ll> go;
  {
    int col = get_col_win(s, e);
    if (col == 1) {
      ret[0][1] = 1;
    } else {
      ret[1][1] = 1;
    }
  }
  {
    int col = get_col_lose(s, e);
    if (col == 1) {
      ret[0][0] = 1;
    } else {
      ret[1][0] = 1;
    }
  }
  return ret;
}

bool dp[2][2];
bool ndp[2][2];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  vector <ll> s(t), e(t);
  for (int i = 0; i < t; ++i) {
    cin >> s[i] >> e[i];
  }
  /*auto rofl = get(s[1], e[1]);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      cout << rofl[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;*/
  dp[0][0] = 1;
  dp[1][1] = 1;
  for (int i = t - 1; i >= 0; --i) {
    auto cur = get(s[i], e[i]);
    for (int j = 0; j <= 1; ++j) {
      for (int k = 0; k <= 1; ++k) {
        ndp[j][k] = 0;
      }
    }
    for (int j = 0; j <= 1; ++j) {
      for (int k = 0; k <= 1; ++k) {
        for (int t = 0; t <= 1; ++t) {
          ndp[j][t] |= (cur[j][k] & dp[k][t]);
        }
      }
    }
    /*cout << "cur\n";
    for (int j = 0; j <= 1; ++j) {
      for (int k = 0; k <= 1; ++k) {
        cout << dp[j][k] << ' ';
      }
      cout << endl;
    }
    cout << "en\n";*/
    swap(dp, ndp);
  }
  cout << dp[0][1] << ' ' << dp[0][0] << '\n';
}