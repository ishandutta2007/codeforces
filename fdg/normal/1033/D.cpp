#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

using namespace std;

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

long long arr[505];

map<long long, int> f;

long long check(long long x, int pw) {
  long long root = pow(1.0 * x, 1.0 / pw);

  for (int i = max(2LL, root - 3); i <= root + 3; ++i) {
    long long nx = x, cnt = 0;
    while (nx % i == 0) {
      nx /= i;
      ++cnt;
    }
    if (nx == 1 && cnt == pw) {
      return i;
    }
  }

  return -1;
}

int mod = 998244353;

int main() {
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  
    for (int pw = 4; pw >= 2; --pw) {
      long long v = check(arr[i], pw);
      if (v != -1) {
        // cout << "Found: " << v << " " << pw << endl;
        f[v] += pw;
        arr[i] = 1;
        break;
      }
    }
  }

  while (true) {
    bool found = false;

    for (pair<long long, int> p : f) {
      for (int i = 0; i < n; ++i) {
        if (arr[i] % p.first == 0) {
          found = true;
          f[p.first]++;
          f[arr[i] / p.first]++;
          arr[i] = 1;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        long long x = gcd(arr[i], arr[j]);
        if (x != 1 && arr[i] != x && arr[j] != x) {
          // cout << x << endl;
          found = true;
          f[x] += 2;
          f[arr[i] / x]++;
          f[arr[j] / x]++;
          arr[i] = 1;
          arr[j] = 1;
        }
      }
    }

    if (!found) break;
  }

  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > 1) {
      int cnt = 0;
      for (int j = n - 1; j >= i; --j) {
        if (arr[i] == arr[j]) {
          ++cnt;
          arr[j] = 1;
        }
      }
      ans = 1LL * (cnt + 1) * (cnt + 1) * ans % mod;
    }
  }
  for (pair<long long, int> p : f) {
    // cout << p.first << "  " << p.second << endl;
    ans = 1LL * (p.second + 1) * ans % mod;
  }
  cout << ans << endl;
  return 0;
}