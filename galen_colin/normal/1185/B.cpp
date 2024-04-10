#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;
const ll mod = 1e9 + 7;

ll n, t, T, d, ans = 0;
string s1, s2;
pair<int, int> a[2][1000003]; //char, len

int main() {
  io;
  cin >> T;
  f0r(t, T) {
    cin >> s1 >> s2;
    int pt = 0, opt1 = 0;
    f1r(i, 1, s1.length() + 1) {
      if (i == s1.length() || s1[i] != s1[pt]) {
        a[0][opt1++] = make_pair(s1[pt], i - pt);
        pt = i;
      }
    }
    pt = 0;
    int opt2 = 0;
    f1r(i, 1, s2.length() + 1) {
      if (i == s2.length() || s2[i] != s2[pt]) {
        a[1][opt2++] = make_pair(s2[pt], i - pt);
        pt = i;
      }
    }
    // cout << opt1 << " " << opt2 << endl;
    // f0r(i, opt1) cout << a[0][i].first << " " << a[1][i].first << " " << a[0][i].second << " " << a[1][i].second << endl;
    if (opt1 != opt2) {
      cout << "NO" << endl;
      continue;
    }
    bool f = 0;
    f0r(i, opt1) {
      if (a[0][i].first != a[1][i].first || a[0][i].second > a[1][i].second) {
        cout << "NO" << endl;
        f = 1;
        break;
      }
    }
    if (f) continue;
    cout << "YES" << endl;
  }
}