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
string a, b;
unsigned char ans[200001];

int main() {
  io;
  cin >> n >> a >> b;
  ms(ans, 0);
  for (int i = n-1; i >= 0; i--) {
    // f0r(j, n) cout << (char)(ans[j] < 10 ? ans[j] + '0' : ans[j]);
    cout << endl;
    if (i == n-1) {
      if (a[i] > b[i]) {
        int diff = a[i] - b[i];
        int x = b[i] + (diff>>1);
        while (x > 'z') {
          x -= 26;
          ans[i-1]++;
        }
        ans[i] = x;
      } else {
        int diff = b[i] - a[i];
        int x = a[i] + (diff>>1);
        ans[i] = x;
      }
      continue;
    }
    if (a[i] < b[i]) {
      int diff = b[i] - a[i];
      ans[i] += a[i] + (diff>>1);
      if (diff % 2 != 0) {
        ans[i+1] += 13;
        while (ans[i+1] > 'z') {
          ans[i+1] -= 26;
          ans[i]++;
        }
      }
      while (ans[i] > 'z') {
        ans[i] -= 26;
        ans[i-1]++;
      }
    } else if (a[i] == b[i]) {
      ans[i] = a[i];
    } else {
      int diff = a[i] - b[i];
      ans[i] += b[i] + (diff>>1);
      if (diff % 2 != 0) {
        ans[i+1] += 13;
        while (ans[i+1] > 'z') {
          ans[i+1] -= 26;
          ans[i]++;
        }
      }
      while (ans[i] > 'z') {
        ans[i] -= 26;
        ans[i-1]++;
      }
    }
  }
  f0r(i, n) cout << ans[i];
  cout << endl;
  // cout << "FLUSH PLEASE" << endl;
}