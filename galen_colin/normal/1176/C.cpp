#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int arr[500005];
vector<vector<int> > locs(6);
int pt[6], valid = 0;
int n, l = 0, ans;
const int a[6] = {4, 8, 15, 16, 23, 42};

int main() {
  io;
  cin >> n;
  
  f0r(i, n) {
    int b; cin >> b;
    bool f = 0;
    f0r(j, 6) {
      if (b == a[j]) {
        f = 1; break;
      }
    }
    if (f) arr[l++] = b;
  }
  f0r(i, l) {
    f0r(j, 6) {
      if (arr[i] == a[j]) locs[j].pb(i);
    }
  }

  bool flag = 0;
  ms(pt, 0);
  f0r(pt[0], locs[0].size()) {
    f1r(j, 1, 6) {
      while (pt[j] < locs[j].size() && locs[j][pt[j]] < locs[j - 1][pt[j - 1]]) pt[j]++;

      if (pt[j] >= locs[j].size()) {
        flag = 1;
        break;
      }
    }
    f1r(k, 1, 6) pt[k]++;

    if (flag) break;
    valid++;
  }

  ans = (n - valid * 6);
  cout << ans << endl;
}