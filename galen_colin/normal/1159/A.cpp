#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll i, j;

ll n, q, Q, T, m, k, r, x;
ll a, b, c, d;
string s, t, p;
ll mv = 0;

int main() {
  io;
  int ans = 0, m = 0;
  cin >> n;
  f0r(i, n) {
    char c;
    cin >> c;
    if (c == '-') ans--;
    else ans++;
    m = min(m, ans);
  }
  cout << ans - m << endl;
}