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
int a[101];

int main() {
  io;
  cin >> Q;
  f0r(i, Q) {
    cin >> s;
    f0r(j, s.length()) a[j] = s[j] - '0';
    sort(a, a+s.length());
    bool f = 1;
    f0r(j, s.length() - 1) {
      if(a[j+1] != a[j] + 1) f = 0;
    }
    cout << (f ? "YES" : "NO") << endl;
  }
}