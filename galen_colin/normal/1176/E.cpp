#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int t, n, m, q;
vector<multiset<int> > edges;
bool cov[200002], ans[200002];

int main() {
  io;
  cin >> t;
  f0r(q, t) {
    cin >> n >> m;
    edges = vector<multiset<int> >(n);
    f0r(i, n) cov[i] = 0, ans[i] = 0;
    int k = 0;
    f0r(i, m) {
      int a, b; cin >> a >> b;
      edges[--a].insert(--b);
      edges[b].insert(a);
    }

    f0r(i, n) {
      if (!cov[i]) {
        k++;
        cov[i] = 1;
        ans[i] = 1;
        for (int j: edges[i]) cov[j] = 1;
      }
    }

    int c = 0;
    if (k > n/2) {
      cout << n - k << endl;
      f0r(i, n) {
        if (!ans[i]) {
          if (c++) cout << " ";
          cout << i + 1;
        }
      }
    } else {
      cout << k << endl;
      f0r(i, n) {
        if (ans[i]) {
          if (c++) cout << " ";
          cout << i + 1;
        }
      }
    }
    cout << endl;
  }
}