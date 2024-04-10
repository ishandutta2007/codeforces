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
const ll mod = 998244353;

ll n, q, Q, T, m, k, r, x, y, z, g, b;
string s;
vector<char> v;

int main() {
  io;
  cin >> s;
  n = s.length();
  ll ans = n / 2 + ((n % 4) == 1);
  v = vector<char>(ans);
  int l = 0, r = n - 1;
  while (l <= r) {
    if (r - l < 3) {
      v[l/2] = s[l];
    } else {
      char c;
      if (s[l] == s[r] || s[l] == s[r-1]) c = s[l];
      else if (s[l+1] == s[r]) c = s[r];
      else c = s[r-1];
      v[l/2] = c;
      v[ans - l/2 - 1] = c;
    }
    l += 2;
    r -= 2;
  }
  for (char c: v) cout << c;
  cout << endl;
}