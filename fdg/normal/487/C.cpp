#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool solve(int n) {
  vector<int> v;
  for (int i = 0; i < n; ++i)
    v.push_back(i + 1);
  do {
    set<int> f;
    int cur = 1;
    for (int i = 0; i < v.size(); ++i) {
      cur = cur * v[i] % n;
      f.insert(cur);
    }
    if (f.size() == n) {
      for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
      cout << endl;
    }
  } while (next_permutation(v.begin(), v.end()));
  return false;
}

int mPow(int a, int x, int mod) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    x >>= 1;
    a = 1LL * a * a % mod;
  }
  return ret;
}

int inv(int x, int mod) {
  // for (int i = 1; i < mod; ++i)
  //   if (i * x % mod == 1) return i;
  return mPow(x, mod - 2, mod);
}

bool isPrime(int x) {
  for (int i = 2; i < x; ++i)
    if (x % i == 0) return false;
  return true;
}

int ans[100005], used[100005];
vector<pair<int, int>> v;

bool check(int n) {
  set<int> f;
  int cur = 1;
  for (int i = 0; i < n; ++i) {
    cur = 1LL * cur * ans[i] % n;
    f.insert(cur);
  }
  return f.size() == n;
}

int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) puts("YES\n1");
  else if (n == 2) puts("YES\n1\n2");
  else if (n == 4) puts("YES\n1\n3\n2\n4");
  else if (isPrime(n)) {
    puts("YES");
    ans[0] = 1; ans[n - 1] = n;
    ans[n / 2] = n - 1;
    int l = 1, r = n - 2;
    for (int i = 2; i < n - 1; ++i) {
      if (used[i]) continue;
      int rev = inv(i, n);
      used[i] = used[rev] = true;
      ans[l] = i; ans[r] = rev;
      v.push_back(make_pair(i, rev));
      ++l; --r;
    }
    for (int i = 1; i < n - 1; ++i) {
      ans[i] = 1LL * (i + 1) * inv(i, n) % n;
    }
    while (!check(n)) {
      l = 1; r = n - 2;
      for (int i = 0; i < v.size(); ++i) {
        if (rand() & 1) ans[l] = v[i].first, ans[r] = v[i].second;
        else ans[l] = v[i].second, ans[r] = v[i].first;
        ++l, --r; 
      }
    }
    for (int i = 0; i < n; ++i)
      printf("%d\n", ans[i]);
  } else {
    puts("NO");
  }
  // for (int i = 1; i < 11; ++i)
  //   cout << i << "  " << inv(i, 11) << endl;
  // for (int i = 1; i <= 11; ++i)
  //   solve(i);
  return 0;
}