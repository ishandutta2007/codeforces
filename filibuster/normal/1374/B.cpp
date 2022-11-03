#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int INF = 1e9 + 13;

void solve() {
    int n;
    cin >> n;

    int p = 0;
    while(n % 2 == 0) {
        n /= 2;
        p++;
    }

    int q = 0;
    while(n % 3 == 0) {
        n /= 3;
        q++;
    }

    if(p > q || n > 1) {
        cout << -1 << endl;
        return;
    }

    cout << q - p + q << endl;
//    vector<int> a(n);
//    for(int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

}