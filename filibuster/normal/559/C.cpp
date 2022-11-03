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

bool cmp(pii a, pii b) {
    return a.f + a.s < b.f + b.s;
}

int sum(int a, int b) {
    int res = a + b;

    if(res >= M)
        res -= M;

    return res;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    if(k % 2)
        return pw * 1ll * pw % M * n % M;
    else
        return pw * 1ll * pw % M;
}

int p[N], r[N];

int C(int n, int k) {
    return p[n] * 1ll * r[k] % M * r[n - k] % M;
}

int cnt(int x, int y) {
    return C(x + y, x);
}

pii a[N];
int dp[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    p[0] = 1;
    r[0] = pow2(p[0], M - 2);
    for(int i = 1; i < N; i++) {
        p[i] = p[i - 1] * 1ll * i % M;
        r[i] = pow2(p[i], M - 2);
    }

    int h, w, n;
    cin >> h >> w >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
        a[i].f--;
        a[i].s--;
    }

    a[n] = {h - 1, w - 1};
    n++;

    sort(a, a + n, cmp);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i].f >= a[j].f && a[i].s >= a[j].s) {
                dp[i] = sum(dp[i], dif(cnt(a[j].f, a[j].s), dp[j]) * 1ll *
                            cnt(a[i].f - a[j].f, a[i].s - a[j].s) % M);
            }
        }
    }

    cout << dif(cnt(h - 1, w - 1), dp[n - 1]);
}