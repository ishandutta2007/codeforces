#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 1;
const int A = 1e6 + 13;

/*
42 42 42

*/

int a[N];
bool is[B];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < B)
            is[a[i]] = true;
    }

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for(int i = 1; i < B; i++) if(is[i]) {
        for(int j = 0; j < n; j++)
            if(a[j] >= i)
                ans = max(ans, a[j] % i);
    }
//    cout << ans << endl;

    sort(a, a + n);
    set<int> used;

    for(int i = 0; i < n; i++) {
        if(a[i] < B)
            continue;

        if(used.count(a[i]))
            continue;
        used.insert(a[i]);

        for(int j = 2; (j - 1) * a[i] < A; j++) {
            int ind = lower_bound(a, a + n, j * a[i]) - a - 1;
//            cout << i << ' ' << j << ' ' << ind << ' ' << a[i] << ' ' << a[ind] << ' '
//                    << (j - 1) * a[i] << ' ' << a[ind] % a[i] << endl;

            if(a[ind] >= (j - 1) * a[i])
                ans = max(ans, a[ind] - (j - 1) * a[i]);
        }
    }

    cout << ans << endl;
}