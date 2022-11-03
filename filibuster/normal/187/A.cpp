#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 3e5 + 13;
const int B = 350;

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        a[i]--;
    }

    vector<int> wh(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];

        b[i]--;
        wh[b[i]] = i;
    }

    int lst = -1, cnt = 0;

    int res = 0;
    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << wh[a[i]] << ' '<< lst << endl;
        if(wh[a[i]] < lst) {
            cout << n - i << endl;
            return 0;
        }

        cnt += wh[a[i]] - lst - 1;
        lst = wh[a[i]];

        if(cnt > n - i - 1) {
            cout << n - i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}