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
int a[200001], cnt[200001];
vector<pair<int, pii> > ans;

int main() {
  io;
  cin >> n;
  f0r(i, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int mi = 0;
  f0r(i, 200001) {
    if (cnt[i] > cnt[mi]) mi = i;
  }
  int v = mi;
  int pt;
  f0r(pt, n) {
    if (a[pt] == v) {
      for (int x = pt - 1; x >= 0; x--) {
        if (a[x] != v) {
          if (a[x] < v) {
            ans.pb(mp(1, mp(x, x+1)));
          } else {
            ans.pb(mp(2, mp(x, x+1)));
          }
          a[x] = v;
        } else break;
      }
    }
  }
  reverse(a, a+n);
  f0r(pt, n) {
    if (a[pt] == v) {
      for (int x = pt - 1; x >= 0; x--) {
        if (a[x] != v) {
          if (a[x] < v) {
            ans.pb(mp(1, mp(n-x-1, n-x-2)));
          } else {
            ans.pb(mp(2, mp(n-x-1, n-x-2)));
          }
          a[x] = v;
        } else break;
      }
    }
  }
  cout << ans.size() << endl;
  for (auto x: ans) {
    cout << x.f << " " << ++x.s.f << " " << ++x.s.s << endl;
  }
}