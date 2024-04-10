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
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> cnt(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      ++cnt[a[i]];
    }
    vector <int> L(n, -1), R(n, n);
    vector <int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && a[i] <= a[st.back()]) st.pop_back();
      if (!st.empty()) L[i] = st.back();
      st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && a[i] < a[st.back()]) st.pop_back();
      if (!st.empty()) R[i] = st.back();
      st.push_back(i);
    }
    vector <vector <int>> en(n + 2);
    for (int i = 0; i < n; ++i) {
      int len = R[i] - L[i] - 1;
      en[len + 1].push_back(a[i]);
    }
    vector <int> bad(n + 1);
    set <int> mex;
    for (int i = 0; i < n; ++i) if (cnt[i] == 0) mex.insert(i);
    for (int len = 1; len <= n; ++len) {
      for (auto x : en[len]) {
        --cnt[x];
        if (cnt[x] == 0) mex.insert(x);
      }
      if (!mex.empty() && *mex.begin() <= n - len) bad[len] = 1;
    }
    for (int i = 1; i <= n; ++i) cout << !bad[i];
    cout << '\n';
  }
}