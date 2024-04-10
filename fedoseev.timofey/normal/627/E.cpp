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
 	
typedef long long ll;
 
using namespace std;	

const int N = 3007;

int prv[N], nxt[N];
int cnt_col[N];

vector <int> who[N];

int main() {	
  ios_base::sync_with_stdio(false); cin.tie(0);	
#ifdef LOCAL	
  freopen("input.txt", "r", stdin);	
#endif	
  int r, c, n, k;
  cin >> r >> c >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    who[x].push_back(y);
  }
  ll ans = 0;
  for (int u = 0; u < r; ++u) {
    fill(cnt_col, cnt_col + c + 2, 0);
    for (int i = u; i < r; ++i) {
      for (int y : who[i]) {
        ++cnt_col[y + 1];
      }
    }
    prv[0] = 0, nxt[c + 1] = c + 1;
    for (int i = 1; i <= c + 1; ++i) {
      if (cnt_col[i - 1] > 0) prv[i] = i - 1;
      else prv[i] = prv[i - 1];
    }
    for (int i = c; i >= 0; --i) {
      if (cnt_col[i + 1] > 0) nxt[i] = i + 1;
      else nxt[i] = nxt[i + 1];
    }
    auto get = [&] (int r) {
      ll ret = 0;
      if (cnt_col[r] == 0) return 0LL;
      int l = r, sum = cnt_col[r];
      while (sum < k) {
        if (prv[l] == l) break;
        l = prv[l];
        sum += cnt_col[l];
      }
      if (sum >= k) {
        ret += l * (nxt[r] - r);
      }
      return ret;
    };

    auto rofl = [&] (int r1, int r2) {
      ll ret = 0;
      int r = r2, l = r2;
      int sum = cnt_col[r];
      while (true) {
        while (sum < k) {
          if (prv[l] == l) break;
          l = prv[l];
          sum += cnt_col[l];
        }
        if (cnt_col[r] > 0 && sum >= k) {
          ret += l * (nxt[r] - r);
        }
        sum -= cnt_col[r];
        if (r == r1) break;
        r = prv[r];
      }
      return ret;
    };

    ll cur = 0;
    auto del = [&] (int y) {
      int ly = prv[y], ry = y;
      for (int i = 0; i < k; ++i) {
        ry = nxt[ry];
      }
      cur -= rofl(ly, ry);
      --cnt_col[y];
      if (cnt_col[y] == 0) {
        nxt[prv[y]] = nxt[y];
        prv[nxt[y]] = prv[y];
        prv[y] = nxt[y] = -1;
      }
      cur += rofl(ly, ry);
    };

    for (int i = 1; i <= c; ++i) {
      if (cnt_col[i] > 0) {
        cur += get(i);
      }
    }

    for (int d = r - 1; d >= u; --d) {
      ans += cur;
      for (int y : who[d]) {
        del(y + 1);
      }
    }
  } 
  cout << ans << '\n';
}