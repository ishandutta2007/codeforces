#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j;
typedef long long ll;

ll n, m, p, q, Q, k, r;
ll a[100001];
ll ans = 0, page = 0, disp = 0;

int main() {
  io;
  cin >> n;
  f0r(i, n) cin >> a[i];
  ll mv = 0;
  sort(a, a+n);

  int cnt = 0, loc = -1;
  f1r(i, 1, n) {
    if (a[i] == a[i-1]) {
      cnt++;
      loc = i;
    }
  }
  if (cnt > 1) {
    cout << "cslnb" << endl;
    exit(0);
  }
  if (cnt > 0) {
    if (a[loc] == 0) {
      cout << "cslnb" << endl;
      exit(0);
    }
    a[loc]--;
    sort(a, a+n);
    f1r(i, 1, n) {
      if (a[i] == a[i-1]) {
        cout << "cslnb" << endl;
        exit(0);
      }
    }
    mv = 1;
  }

  mv += a[0];
  a[0] = 0;
  f1r(i, 1, n) {
    if (a[i] - a[i-1] > 1) {
      mv += a[i] - a[i-1] - 1;
      a[i] = a[i-1] + 1;
    }
  }
  cout << (mv % 2 ? "sjfnb" : "cslnb") << endl;
}