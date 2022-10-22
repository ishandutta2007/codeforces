#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int INF = 0x3f3f3f3f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int a[n];
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);

  int cur = 1;
  for (int i=0; i<n; i++) {
    if (a[i] >= cur) {
      cur++;
    }
  }
  cout << cur-1 << nl;

  return 0;
}