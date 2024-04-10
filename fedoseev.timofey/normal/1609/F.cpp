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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
ll stupid(vector<ll> a) {
  int n = a.size();
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll mx = a[i], mn = a[i];
    for (int j = i; j < n; ++j) {
      mx = max(mx, a[j]);
      mn = min(mn, a[j]);
      if (__builtin_popcountll(mx) == __builtin_popcountll(mn)) {
        ++ans;
      }
    }
  }
  return ans;
}
 
ll smart(vector<ll> a) {
  int n = a.size();
  vector<int> cnt(n);
  for (int i = 0; i < n; ++i) {
    cnt[i] = __builtin_popcountll(a[i]);
  }
  vector<int> l_mx(n), r_mx(n);
  vector<int> l_mn(n), r_mn(n);
  {
    vector<int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
      l_mx[i] = (st.empty() ? -1 : st.back());
      st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
      r_mx[i] = (st.empty() ? n : st.back());
      st.push_back(i);
    }
    st.clear();
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && a[st.back()] > a[i]) st.pop_back();
      l_mn[i] = (st.empty() ? -1 : st.back());
      st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
      r_mn[i] = (st.empty() ? n : st.back());
      st.push_back(i);
    }
    st.clear();
  }
  
  vector<int> l_bit(n), r_bit(n);
  for (int bit = 0; bit < 70; ++bit) {
    vector<int> where(n, -1);
    for (int i = 0; i < n; ++i) {
      if (cnt[i] == bit) {
        l_bit[i] = (l_mn[i] == -1 ? -1 : where[l_mn[i]]);
        where[i] = i;
      } else {
        where[i] = (l_mn[i] == -1 ? -1 : where[l_mn[i]]);
      }
    }
    where.assign(n, -1);
    for (int i = n - 1; i >= 0; --i) {
      if (cnt[i] == bit) {
        r_bit[i] = (r_mn[i] == n ? n : where[r_mn[i]]);
        where[i] = i;
      } else {
        where[i] = (r_mn[i] == n ? n : where[r_mn[i]]);
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans -= (ll)(min(r_mx[i], r_mn[i]) - i) * (i - max(l_mx[i], l_mn[i]));
  }
  for (int tt = 0; tt < 2; ++tt) {
    const int K = 22;
    vector<vector<int>> goR(K, vector<int>(n + 1));
    vector<ll> sumR(n + 1);
    vector<ll> allR(n + 1);
    {
      for (int i = 0; i < n; ++i) {
        goR[0][i] = r_bit[i];
      }
      goR[0][n] = n;
      for (int i = n - 1; i >= 0; --i) {
        allR[i] = (ll)(r_mn[i] - i) * l_mn[i];
        sumR[i] = r_mn[i] - i;
        if (r_bit[i] != n) {
          allR[i] += allR[r_bit[i]];
          sumR[i] += sumR[r_bit[i]];
        }
      }
      for (int j = 1; j < K; ++j) {
        for (int i = 0; i <= n; ++i) {
          int nxt = goR[j - 1][i];
          goR[j][i] = goR[j - 1][nxt];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      int L = l_mx[i], R = r_mx[i];
      /*int cur = i;
      while (cur < R) {
        ans += (ll)(min(R, r_mn[cur]) - cur) * (i - max(L, l_mn[cur]));
        cur = r_bit[cur];
      }*/
      int cur = i;
      for (int j = K - 1; j >= 0; --j) {
        int nxt = goR[j][cur];
        if (nxt < R && r_bit[nxt] < R && l_mn[nxt] >= L) {
          ans += (sumR[cur] - sumR[nxt]) * i;
          ans -= allR[cur] - allR[nxt];
          cur = nxt;
        }
      }
      {
        int rofl = 1;
        while (cur < R && rofl > 0) {
          ans += (ll)(min(R, r_mn[cur]) - cur) * (i - max(L, l_mn[cur]));
          cur = r_bit[cur];
          --rofl;
        }
      }
      for (int j = K - 1; j >= 0; --j) {
        int nxt = goR[j][cur];
        if (nxt < R && r_bit[nxt] < R) {
          ll sum = sumR[cur] - sumR[nxt];
          ans += sum * i;
          ans -= sum * L;
          cur = nxt;
        }
      }
      while (cur < R) {
        ans += (ll)(min(R, r_mn[cur]) - cur) * (i - max(L, l_mn[cur]));
        cur = r_bit[cur];
      }
    }
 
    for (int i = 0; i < n; ++i) {
      l_mx[i] = n - l_mx[i] - 1;
      r_mx[i] = n - r_mx[i] - 1;
      l_mn[i] = n - l_mn[i] - 1;
      r_mn[i] = n - r_mn[i] - 1;
      l_bit[i] = n - l_bit[i] - 1;
      r_bit[i] = n - r_bit[i] - 1;
    }
    reverse(l_mn.begin(), l_mn.end());
    reverse(r_mn.begin(), r_mn.end());
    reverse(l_mx.begin(), l_mx.end());
    reverse(r_mx.begin(), r_mx.end());
    reverse(l_bit.begin(), l_bit.end());
    reverse(r_bit.begin(), r_bit.end());
    swap(l_mx, r_mx);
    swap(l_mn, r_mn);
    swap(l_bit, r_bit);
 
  }
  return ans;
}
 
 
void stress() {
  int tt = 1000000;
  mt19937 rnd(123);
  while (tt--) {
    int n = rnd() % 10 + 1;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) a[i] = rnd() % 10 + 1;
    ll sm = smart(a);
    ll st = stupid(a);
    if (sm != st) {
      cout << n << '\n';
      for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
      }
      cout << '\n';
      exit(0);
    }
    if (tt % 100 == 0) {
      cout << tt << '\n';
    }
  }
  exit(0);
}
 
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  //stress();
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << smart(a) << '\n';
}