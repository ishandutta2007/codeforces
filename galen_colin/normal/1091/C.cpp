#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
ll i, j;

ll n, q, Q, T, m, k, r, x;
set<ll> fct;
set<ll> ans;

int main() {
  io;
  cin >> n;
  ll end = floor(sqrt(n));
  f1r(i, 1, end+1) if (n % i == 0) fct.insert(i), fct.insert(n/i);
  for (ll i: fct) ans.insert(n/i * (n + 2 - i) / 2);
  for (ll i: ans) cout << i << " ";
}