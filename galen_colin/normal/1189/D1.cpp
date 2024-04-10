#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j;
typedef long long ll;

ll n, q, Q, k;
int deg[100001];
vector<int> edges[100001];

int main() {
  io;
  cin >> n;
  f0r(i, n-1) {
    int a, b; cin >> a >> b; a--; b--;
    deg[a]++; deg[b]++;
    edges[a].pb(b); edges[b].pb(a);
  }
  bool f = 1;
  f0r(i, n) {
    f = f & (deg[i] != 2);
  }
  cout << (f ? "YES" : "NO") << endl;
}