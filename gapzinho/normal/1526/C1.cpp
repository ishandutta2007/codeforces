#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 2e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


int n;
int a[ms];
priority_queue<int, vector<int>, greater<int>> pq;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int n;
    cin >> n;
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(a[i] >= 0) {
        ans++;
        cur += a[i];
      } else {
        if(cur + a[i] >= 0) {
          cur += a[i];
          ans++;
          pq.emplace(a[i]);
        } else if(!pq.empty() && pq.top() < a[i]) {
            cur += a[i] - pq.top();
            pq.pop();
            pq.emplace(a[i]);
        }
      }
    }
    cout << ans << endl;

    return 0;
}