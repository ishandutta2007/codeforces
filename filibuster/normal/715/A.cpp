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

/*
5 10
99.99
*/

void solve() {
    int n;
    cin >> n;

    li x = 2;
    for(int i = 1; i <= n; i++) {
//        cout << x << " -> " << x + i * ((i + 1) * 1ll * (i + 1) * i - i + 1) << " -> ";
//        x = sqrt(x + i * ((i + 1) * 1ll * (i + 1) * i - i + 1)) + 0.001;
//        cout << x << endl;
        if(i == 1)
            cout << 2 << endl;
        else
            cout << (i + 1) * 1ll * (i + 1) * i - i + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}