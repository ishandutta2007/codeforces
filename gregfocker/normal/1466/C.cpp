#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    n = (int) s.size();
    for (int i = 1; i <= n; i++) {
      a[i] = s[i - 1] - 'a';
    }
    int y = (int) 1e9, ret = 0;
    for (int i = 1; i <= n; i++) {
      if (i >= 2 && a[i] == a[i - 1]) {
        ret++;
        a[i] = ++y;
      }
      if (i >= 3 && a[i] == a[i - 2]) {
        ret++;
        a[i] = ++y;
      }
    }
    cout << ret << "\n";
  }
}