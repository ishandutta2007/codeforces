#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<long long> v;
long long T, A, B, ans;

long long calc(long long x) {
  long long ret = 0, pw = 1;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] > 4e+18 / pw || ret > 2e+18) return -1;
    ret += pw * v[i];
    pw *= x;
  }
  return ret;
}

void go(int left) {
  if (left == 0) {
    if (calc(T) == A && calc(A) == B) ++ans;
    return;
  }
  for (int i = (left == 1 ? 0 : 0); i <= 11; ++i) {
    v.push_back(i);
    go(left - 1);
    v.pop_back();
  }
}

long long get(long long a, long long x) {
  long long ret = 1;
  for (int i = 0; i < x; ++i) {
    if (ret > 4e+18 / a) return -1;
    ret *= a;
  }
  return ret;
}

long long solve(long long t, long long a, long long b) {
  if (a == 1) {
    if (t != 1) {
      return (b == 1);
    }
  }
  if (t == a) {
    if (a != b) {
      return 0;
    } else {
      if (t == 1) {
        return -1;
      }
      return 2;
    }
  }
  if (a == b) {
    return 1;
  }
  if (t == 1) {
    for (int i = 1; ; ++i) {
      long long pw = get(a, i);
      if (pw == -1) break;
      if (pw == b) return 1;
    }
  }
  // if (t <= a && a <= b) {
    long long ret = 0;
    // for (int n = 1; n <= 60; ++n) {
    //   long long pw = get(t, n);
    //   if (pw == -1) continue;
    //   long long a1 =  
    // }
    v.clear();
    long long sum = 0;
    for (int i = 0; i <= 60; ++i) {
      long long pw = get(a, i), pw1 = get(a, i + 1);
      if (pw == -1) break;
      v.push_back(((b - sum) % (pw1 == -1 ? (b - sum + 1) : pw1)) / pw);
      if (v.back() > 4e+18 / pw) break;
      sum += v.back() * pw;
    }
    if (calc(t) == a && calc(a) == b) ret = 1;
    // for (int u : v)
    //   cout << u << "  ";
    // cout << endl;
    v.clear();

    // v.clear();
    // sum = 0;
    // for (int i = 0; i <= 60; ++i) {
    //   long long pw = get(t, i), pw1 = get(t, i + 1);
    //   if (pw == -1) break;
    //   v.push_back(((a - sum) % (pw1)) / pw);
    //   if (v.back() > 4e+18 / pw) break;
    //   sum += v.back() * pw;
    // }
    // if (calc(t) == a && calc(a) == b) ret = 1;
    // for (int u : v)
    //   cout << u << "  ";
    // cout << endl;
    // if ((b - a) % (a - t) == 0) ret = 1;
    return ret;
  // }
  return 0;
}

long long my(long long t, long long a, long long b) {
  T = t; A = a; B = b; ans = 0;
  go(6);
  return ans;
}

int main() {
  // for (int t = 1; t <= 10; ++t)
  //   for (int a = 1; a <= 10; ++a)
  //     for (int b = 1; b <= 10; ++b)
  //       if (solve(t, a, b) != my(t, a, b)) {
  //         cout << t << "  " << a << " " << b << " " << solve(t, a, b) << "  " << my(t, a, b) << endl;
  //         // return 0;
  //       }
  // // cout << solve(1, 2, 17) << endl;
  // return 0;

  long long t, a, b;
  cin >> t >> a >> b;

  // T = 2; A = 4; B = 16;
  // go(4);
  // cout << ans << endl;
  // return 0;
  // t = 2; a = 4; b = 16;

  long long ret = solve(t, a, b);
  if (ret == -1) cout << "inf\n";
  else cout << ret << endl;
  return 0;
}