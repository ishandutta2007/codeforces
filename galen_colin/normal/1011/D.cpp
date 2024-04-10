#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int m, n, p[31];

int query(int i) {
  cout << i << endl;
  int ans; cin >> ans;
  if (ans == 0) exit(0);
  return ans;
}

void bins(int l, int h) {
  i = (i + 1) % n;
  int mid = (l + h) / 2;

  if ((query(mid) == 1) ^ p[i]) { //x is greater
    bins(mid + 1, h);
  } else { //x is less
    bins(l, mid - 1);
  }
}

int main() {
  cin >> m >> n;
  for (i = 0; i < n; i++) p[i] = (query(1) == -1); //inv
  i = -1;
  bins(1, m);
}