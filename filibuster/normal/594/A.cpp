#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = INF;
    for(int i = 0; i < n / 2; i++)
        ans = min(ans, a[i + n / 2] - a[i]);

    cout << ans << endl;
//    int res1 = 0, res2 = 0;
//    for(int i = 0; i < n; i++) {
//        if(i % 2 == 0) {
//            res1 = max(res1, a[i + 1] - a[i]);
//        } else {
//            res2 = max(res2, a[i + 1] - a[i]);
//        }
//    }
//
//    cout << min(res1, res2);
}