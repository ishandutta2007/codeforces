#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll root(ll x) {
    ll ans = sqrtl(ld(x));
    while (ans * ans < x) ++ans;
    while (ans * ans > x) --ans;
    return ans;
}

vector<ll> solve(ll a) {
    ll D = 1 + 8 * a;
    ll d = root(D);
    vector<ll> ans;
    if (d * d != D) {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    ans.push_back((1 + d) / 2);
    ans.push_back((1 - d) / 2);
    return ans;
}

void fail() { cout << "Impossible" << endl; exit(0); }

ll a00, a01, a10, a11;
char s[1001005];

int main()
{
    cin >> a00 >> a01 >> a10 >> a11;
    if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
        cout << 0;
        return 0;
    }

    vector<ll> v0 = solve(a00), v1 = solve(a11);
    for (int ttt = 0; ttt < 2; ++ttt) {
        for (int i = 0; i < 2; ++i) {
            if (v0[i] < 0) continue;
            for (int j = 0; j < 2; ++j) {
                if (v1[j] < 0) continue;

                ll k0 = v0[i];
                ll k1 = v1[j];

                ll sum = a00 + a01 + a10 + a11;
                ll rs = solve(sum)[0];
                if (rs != k0 + k1) continue;

                if (a01 + a10 != k0 * k1) continue;

                if (k0 == 0) {
                    for (int z = 0; z < k1; ++z)
                        s[z] = '1' ^ ttt;
                    s[k1] = 0;
                    puts(s);
                    return 0;
                }
                if (k1 == 0) {
                    for (int z = 0; z < k0; ++z)
                        s[z] = '0' ^ ttt;
                    s[k0] = 0;
                    puts(s);
                    return 0;
                }

                int idx = 0;
                int qqq = a01 / k1;
                while (qqq--)
                    s[idx++] = '0' ^ ttt;
                qqq = k1 - a01 % k1;
                while (qqq--)
                    s[idx++] = '1' ^ ttt;
                if (a01 % k1 != 0)
                    s[idx++] = '0' ^ ttt;
                qqq = a01 % k1;
                while (qqq--)
                    s[idx++] = '1' ^ ttt;
                qqq = k0 + k1 - idx;
                while (qqq--)
                    s[idx++] = '0' ^ ttt;
                s[idx] = 0;
                puts(s);

                return 0;
            }
        }

        swap(a00, a11);
        swap(a01, a10);
        swap(v0, v1);
    }

    fail();

    return 0;
}