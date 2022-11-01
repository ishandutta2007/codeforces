// April 3, 2020
// https://codeforces.com/contest/768/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = (1 << 21);

int h, g;
int n;
int a[N];

int level(int x) { // levels are 0-indexed
  return 31 - __builtin_clz(x);
}

bool can_call(int x) {
  if (a[x] == 0) {
    return false;
  }
  int l = 2 * x;
  int r = 2 * x + 1;
  if (level(x) == g - 1) {
    return (a[l] != 0 || a[r] != 0);
  }
  if (a[l] > a[r]) {
    return can_call(l);
  }
  return can_call(r);
}

void remove(int x) {
  int l = 2 * x;
  int r = 2 * x + 1;
  if (a[l] == 0 && a[r] == 0) {
    a[x] = 0;
    return;
  }
  if (a[l] > a[r]) {
    a[x] = a[l];
    remove(l);
  } else {
    a[x] = a[r];
    remove(r);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    cin >> h >> g;
    fill(a, a + (1 << (h + 1)), 0);
    n = (1 << h) - 1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> call;
    for (int i = 1; i <= n; i++) {
      while (can_call(i)) {
        remove(i);
        call.push_back(i);
      }
    }
    long long ans = 0;
    for (int i = 1; i < (1 << g); i++) {
      ans += a[i];
    }
    cout << ans << '\n';
    for (int i = 0; i < (int) call.size(); i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << call[i];
    }
    cout << '\n';
  }


  return 0;
}