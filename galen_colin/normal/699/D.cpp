#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int n, a[200002], cnt = 0, root = -1;
int cov[200002];

int main() {
  io;
  cin >> n;
  f0r(i, n) {
    cin >> a[i];
    a[i]--;
    if (root == -1 && a[i] == i) root = i;
  }
  f0r(i, n) cov[i] = n + 1;
  f0r(i, n) {
    if (cov[i] < i) continue;
    int foc = i;
    while (foc != root) {
      cov[foc] = i;
      foc = a[foc];
      if (cov[foc] == i) {
        if (root == -1) root = foc;
        a[foc] = root;
        cnt++;
      } else if (cov[foc] < i) break;
    }
  }
  cout << cnt << endl;
  f0r(i, n) {
    if (i) cout << " ";
    cout << a[i] + 1;
  }
  cout << endl;
}