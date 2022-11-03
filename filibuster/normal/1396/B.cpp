#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int A = 26;

/*
1
2
2 2
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int lst = -1;
    int cur = 0;
    while(true) {
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(i != lst && (mx == -1 || a[mx] < a[i])) {
                mx = i;
            }
        }
        if(mx == -1 || a[mx] == 0)
            break;

        a[mx]--;
        lst = mx;
        cur++;
    }

    cout << (cur % 2 == 1 ? "T" : "HL") << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}