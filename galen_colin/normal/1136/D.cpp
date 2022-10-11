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
set<pii> a;
set<int> s[300003];

int main() {
  io;
  cin >> n >> m;
  f0r(i, n) {
    pii b = {n-i, 0};
    cin >> b.s;
    --b.s;
    a.insert(b);
  }
  f0r(i, m) {
    int x, y; cin >> x >> y;
    s[--x].insert(--y);
  }
  int ans = 0;
  int nid = (*a.begin()).s;
  auto it = a.begin();
  it++;
  while (it != a.end()) {
    int cid = (*it).s;
    if (s[cid].find(nid) != s[cid].end()) {
      auto target = ++(a.begin());
      auto oit = it;
      bool f = 0;
      if (oit == target) f = 1;
      while (oit != target) {
        oit--;
        int q = (*oit).s;
        if (s[cid].find(q) == s[cid].end()) {
          break;
        }
        if (oit == target) f = 1;
      }
      if (f) {
        ans++;
        a.erase(it++);
      } else ++it;
    } else ++it;
  }
  cout << ans << endl;
}