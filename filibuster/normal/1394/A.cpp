#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e6 + 13;

/*
*/

void solve() {
    int n, d, m;
    cin >> n >> d >> m;

    vector<int> a(n);
    int k = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] <= m)
            k++;
    }

    sort(a.begin(), a.end());

    if(k == n) {
        li s = 0;
        for(auto x : a)
            s += x;
        cout << s << endl;
        return;
    }

    vector<li> s(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i - 1];
    }

    li ans = s[k] + a[n - 1];
    for(int i = 2; i <= n - k; i++) {
        li x = (i - 1) * d + i;

        li res = 0;
        if(x > n - k) {
            if(x > n) {
                break;
            }
            res += s[n] - s[n - i] + s[k] - s[x - n + k];
        } else {
            res = s[k] + s[n] - s[n - i];
        }
        ans = max(ans, res);
    }

    cout << ans << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}