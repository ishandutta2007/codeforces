#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll i, j;

ll n, q, Q, T, m, k, r, x;
ll a, b, c, d;
string s, t, p;
ll mv = 0;
bool dp[1000001];

int main() {
  io;
  cin >> n;
  string a = "I hate ", b = "I love ";
  string ans = "";
  f0r(i, n) {
    ans += (i % 2 ? b : a);
    ans += (i == n - 1 ? "it" : "that ");
  }
  cout << ans << endl;
}