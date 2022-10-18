#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool used[2 * 3 * 100000 + 15];
vector<int> q;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

long long cnt(int n, int g) {
  long long ret = 0;
  for (int mod = 0; mod < g && mod <= n; ++mod) {
    long long mn = mod, mx = (n / g + 2) * g + mod;
    while (mx > n) mx -= g;

    long long cnt = (mx - mn) / g + 1;
    long long sum = (mn + mx) * cnt / 2 - mod * cnt;

    ret += sum / g;
    // cout << "Y: " << mod << "  " << mn << " " << mx << "  " << cnt << " " << sum << endl;
  }
  // cout << "X: " << n << "  " << g << " " << ret << endl;

  return ret + n + 1;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  
  int SZ = 3 * (a + b);
  // SZ = n;

  long long ans = 0, curCnt = 0;
  used[0] = true;
  int qPos = 0;
  for (int i = 0; i <= SZ && i <= n; ++i) {
    if (used[i]) {
      q.push_back(i);
      curCnt++;
    }
    while (qPos < q.size()) {
      {
        int nx = q[qPos] + a;
        if (nx >= 0 && nx <= SZ) {
          if (nx <= i && !used[nx]) {
            q.push_back(nx);
            curCnt++;
          }
          used[nx] = true;
        }
      }
      {
        int nx = q[qPos] - b;
        if (nx >= 0 && nx <= SZ) {
          if (nx <= i && !used[nx]) {
            q.push_back(nx);
            curCnt++;
          }
          used[nx] = true;
        }
      }

      ++qPos;
    }

    ans += curCnt; 
  }

  int g = gcd(a, b);
  if (n > SZ) {
    ans += cnt(n, g) - cnt(SZ, g);
  }
  cout << ans << endl;

  return 0;
}