// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 505 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

int n, k;
bool vis[maxn];
int dis[maxn], pre[maxn];

int main() {
  scanf("%d%d", &n, &k);
  queue<int> q;
  q.push(0);
  vis[0] = 1;
  dis[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = max(0, u - k); j <= min(n, u + k); j++)
      if ((u + j + k) % 2 == 0) {
        if (!vis[j]) {
          int mx = (k - (j - u)) / 2;
          if (u >= mx && n - u >= k - mx) {
            vis[j] = 1;
            dis[j] = dis[u] + 1;
            pre[j] = u;
            q.push(j);
          }
        }
      }
  }
  if (!vis[n]) {
    puts("-1");
    return 0;
  }
  vi path;
  int x = n;
  while (true) {
    // printf("pp %d\n", x);
    path.pb(x);
    if (x == 0)
      break;
    x = pre[x];
  }
  reverse(path.begin(), path.end());
  vi ans;
  int ansval = 0;
  for (int i = 1; i < path.size(); i++) {
    int d1 = ans.size();
    int d2 = path[i];
    int mx = (k - (d2 - d1)) / 2;
    vi vis(n + 1, 0);
    vi qs;
    for (int j = 0; j < mx; j++) {
      qs.pb(ans[j]);
    }
    for (int j = 0; j < d1; j++)
      vis[ans[j]] = 1;
    ans.erase(ans.begin(), ans.begin() + mx);
    for (int i = 1; i <= n; i++)
      if (vis[i] == 0) {
        if (qs.size() < k)
          qs.pb(i), ans.pb(i);
      }
    printf("?");
    for (auto x : qs)
      printf(" %d", x);
    printf("\n");
    fflush(stdout);
    int r = 0;
    scanf("%d", &r);
    ansval ^= r;
  }
  printf("! %d\n", ansval);
  puts("");
}