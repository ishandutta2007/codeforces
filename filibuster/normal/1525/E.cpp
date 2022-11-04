#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 20 + 4;
const int K = 5e4 + 13;

int sum(int a, int b) {
    a += b;
    if(a >= M)
        a -= M;
    return a;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    if(k & 1)
        return mul(pw, mul(pw, n));
    else
        return mul(pw, pw);
}

int d[N][K];
int p[N];

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cin >> d[i][j];
        }
    }

    int ans = 0;

    p[0] = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = mul(p[i - 1], i);
    }

    int rv = pow2(p[n], M - 2);

    for(int j = 0; j < k; j++) {
//        cout << j << "  ::  " << endl;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            a[i] = d[i][j];

        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++) {
//            cout << i << " : " << endl;
            int res = n - a[i] + 1;
            for(int f = 0; f < i; f++) {
                res = mul(res, a[f] - f - 1);
            }

//            cout << res << endl;

            res = mul(res, p[n - i - 1]);
//            cout << res << endl;
            res = mul(res, rv);

            ans = sum(ans, res);
//            for(int l = 0; l <= n - a[i]; l++) {
//
//            }
        }
    }

    cout << ans << endl;
}