#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

/*
1
228 21 11 3
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int j = 1;
    int ans = 0;
    int cnt = 1;
    for(; j < n; ) {
        int nw = 0;
        ans++;
        for(int i = 0; i < cnt; i++) {
            for(; j < n; j++) {
                nw++;
                if(j == n - 1 || a[j] > a[j + 1]) {
                    j++;
                    break;
                }

            }
        }

        cnt = nw;
    }

    cout << ans << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}