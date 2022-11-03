#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 1;
    int lst = -1, res = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > lst) {
            res++;
            lst = a[i];
        } else {
            lst = a[i];
            res = 1;
        }
        ans = max(ans, res);
    }

    cout << ans << endl;
}