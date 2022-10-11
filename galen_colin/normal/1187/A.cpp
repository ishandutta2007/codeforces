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

int main() {
  io;
  cin >> Q;
  f0r(q, Q) {
    ll s;
    cin >> n >> s >> t;
    cout << 1 + max(n - s, n - t) << endl;
  }
}