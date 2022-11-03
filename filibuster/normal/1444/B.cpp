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

int sum(int a, int b) {
    int res = a + b;

    if(res >= M)
        res -= M;

    return res;
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

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n * 2);
    for(int i = 0; i < n * 2; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int res = 0;
    for(int i = 0; i < n; i++)
        res = (res - a[i] + M) % M;
    for(int i = n; i < n * 2; i++)
        res = (res + a[i]) % M;

    int p = 1, r;
    for(int i = 1; i <= n * 2; i++) {
        p = mul(p, i);
        if(i == n)
            r = pow2(p, M - 2);
    }

    cout << mul(mul(p, mul(r, r)), res) << endl;
}