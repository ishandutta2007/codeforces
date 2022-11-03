#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 120;
const int M = 998244353;

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    if(k % 2)
        return pw * 1ll * pw % M * 1ll * n % M;
    else
        return pw * 1ll * pw % M;
}

int f[N], r[N];
int a[N];

void solve() {
    f[0] = r[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = f[i - 1] * 1ll * i % M;
        r[i] = pow2(f[i], M - 2);
    }

    li n;
    cin >> n;

    vector<li> p;
    for(li i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            p.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    }

    if(n > 1)
        p.push_back(n);

    int q;
    cin >> q;

    while(q--) {
        li x, y;
        cin >> x >> y;

        int ans = 1;
        int suma = 0, sumb = 0;
        for(auto p1 : p) {
            int a = 0, b = 0;
            while(x % p1 == 0) {
                a++;
                x /= p1;
            }

            while(y % p1 == 0) {
                b++;
                y /= p1;
            }

            if(a > b) {
                a -= b;
                ans = ans * 1ll * r[a] % M;
                suma += a;
            } else {
                b -= a;
                ans = ans * 1ll * r[b] % M;
                sumb += b;
            }


//            sum += a;
        }

        ans = ans * 1ll * f[suma] % M * 1ll * f[sumb] % M;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();


}