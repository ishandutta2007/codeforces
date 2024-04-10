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
typedef vector<int> vi;
ll i, j;
const ll mod = 1e9 + 7;
 
ll n, q, Q, T, m, k, r, x, y, z, g;
int a[300001], b[300001];
 
int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i];
  cin >> m;
  f0r(i, m) cin >> b[i];
  sort(a, a+n);
  ll sum = 0;
  f0r(i, n) sum += a[i];
  f0r(i, m) cout << sum - a[n-b[i]] << " ";
}