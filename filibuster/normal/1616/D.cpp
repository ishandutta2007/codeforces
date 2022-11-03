#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e6 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
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
    pw = mul(pw, pw);

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
5
4
1 2 3 4
4
1 1 2 2
2
0 -1
6
3 -2 4 -1 -4 0
1
-100

1
4
1 2 3 4
*/

int a[N];

//bool is(int i, int k, int j) {
//    return ();
//}

void solve() {
    int n;
    cin >> n;

//    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    for(int i = 0; i < n; i++) {
        a[i] -= x;
    }

    li sum = a[0];
    int lst = -1;
    int ans = n;
    li mx = 0;

    for(int i = 1; i < n; i++) {
        sum += a[i];
        if(sum - mx < 0) {
            lst = i;
            sum = a[i + 1];
            mx = 0;
            ans--;
            i++;
        } else {
            mx = max(mx, sum - a[i]);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}