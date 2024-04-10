#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 14;
const int M = 1e9 + 7;
const int N = 5e5 + 13;
const int A = 62;

int sum(int a, int b) {
    int res = a + b;
    if(res >= M)
        res -= M;
    return res;
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}


/*
1
5
5 1 1 1 1
1 2
1 3
1 4
1 5
*/

li a[N];
int cnt[A];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < A; i++) {
        cnt[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < A; j++) {
            if(a[i] & (1ll << j))
                cnt[j]++;
        }
    }

    int ans = 0;
    for(int j = 0; j < n; j++) {
        int sa = 0;
        int so = 0;

        int pw = 1;
        for(int i = 0; i < A; i++) {
            if(a[j] & (1ll << i)) {
                so = sum(so, mul(n, pw));
                sa = sum(sa, mul(cnt[i], pw));
            } else {
                so = sum(so, mul(cnt[i], pw));
            }


            pw = mul(pw, 2);
        }

        ans = sum(ans, mul(so, sa));
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}