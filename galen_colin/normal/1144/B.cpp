#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 

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
typedef pair<ll, ll> pll;
ll i, j;

ll n, q, Q, T, m, k, r, x, y, z, g;
ll b, c, d;
string s;
int a[2001], odd[2001], even[2001], op = 0, ep = 0;

int main() {
  io;
  cin >> n;
  f0r(i, n) {
    cin >> a[i];
    if (a[i] % 2) odd[op++] = a[i];
    else even[ep++] = a[i];
  }
  sort(odd, odd+op);
  sort(even, even+ep);
  reverse(odd, odd+op);
  reverse(even, even+ep);
  int pt = min(op, ep) + 1;
  ll ans = 0;
  while (pt < op) {
    ans += odd[pt++];
  }
  while (pt < ep) {
    ans += even[pt++];
  }
  cout << ans << endl;
}