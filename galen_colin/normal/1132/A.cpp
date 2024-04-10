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
 
int main() {
  io;
  ll a, b, c, d;
  ll cnt[2]; ms(cnt, 0);
  cin >> a >> b >> c >> d;
  cout << ((a == d) && (c == 0 || a) ? "1" : "0") << endl;
}