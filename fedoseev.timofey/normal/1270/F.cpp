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
#include <cassert>

using namespace std;

typedef long long ll;

const int K = 500;
const int N = 2e5 + 7;

int hv[K * N + N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.size();
  vector <int> pref(n + 1);
  for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + (s[i] - '0');
  vector <int> nxt(n, n);
  for (int i = n - 1; i >= 0; --i) {
    if (i + 1 < n) nxt[i] = nxt[i + 1];
    if (i + 1 < n && s[i + 1] == '1') nxt[i] = i + 1;
  }
  vector <int> prv(n + 1, -1);
  for (int i = 0; i <= n; ++i) {
    if (i > 0) prv[i] = prv[i - 1];
    if (i > 0 && s[i - 1] == '1') prv[i] = i - 1;
  }
  ll ans = 0;
  for (int cnt = 1; cnt <= K; ++cnt) {
    int lst = -1;
    for (int i = n - 1; i >= 0; --i) {
      if (lst == -1) {
        if (pref[n] - pref[i] == cnt) {
          lst = prv[n];
        }
      } else if (s[i] == '1') {
        lst = prv[lst];
      }
      if (lst == -1) continue;
      int l = lst - i + 1;
      int r = nxt[lst] - i;
      r -= (r % cnt);
      l += ((cnt - (l % cnt)) % cnt);
      if (r >= l) {
        ans += (r - l) / cnt + 1;
      }
    }
  }

  for (int cnt = 1; cnt <= n / K + 1; ++cnt) {
    queue <int> q;
    q.push(0);
    for (int i = 1; i <= n; ++i) {
      while (!q.empty() && pref[i] - pref[q.front()] > K) {
        int id = q.front();
        q.pop();
        ++hv[K * N + id - cnt * pref[id]];
      }
      ans += hv[K * N + i - cnt * pref[i]];
      q.push(i);
    }
    for (int i = 0; i <= n; ++i) {
      hv[K * N + i - cnt * pref[i]] = 0;
    }
  }

  cout << ans << '\n';
}