#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int a[N], b[N];

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < k; i++) {
        cin >> b[i];
        b[i]--;
    }

    li ans = 0;

    sort(a, a + n);
    sort(b, b + k);


    int cnt = 0;
    for(int j = 0; j < k; j++) {
        ans += a[n - j - 1];
        if(b[j] == 0) {
            ans += a[n - j - 1];
            cnt++;
        }
    }

    reverse(b, b + k);

    n -= k;


    for(int i = 0, j = 0; i < n; j++) {
        ans += a[i];
        i += b[j];
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}