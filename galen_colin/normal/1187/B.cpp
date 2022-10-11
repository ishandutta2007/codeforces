#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j;
typedef long long ll;

ll n, q, Q, t, T, m, k;
string s;
string s2;
int pre[200001][27];
int cnt[27];

int main() {
  io;
  cin >> n >> s >> m;
  ms(pre, 0);
  f0r(i, 26) pre[0][i] = (s[0] - 'a' == i);
  f1r(j, 1, n) {
    f0r(i, 26) {
      pre[j][i] = pre[j - 1][i] + (s[j] - 'a' == i);
    }
  }

  f0r(q, m) {
    cin >> s2;
    int len = s2.length();
    ms(cnt, 0);

    f0r(i, len) {
      cnt[s2[i] - 'a']++;
    }

    // f0r(i, 26) cout << cnt[i] << endl;

    int l = 1, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      bool cond = 1;

      f0r(i, 26) {
        if (pre[mid - 1][i] < cnt[i]) cond = 0;
      }

      if (!cond) l = mid + 1;
      else r = mid - 1;
    }

    cout << l << endl;
  }
}