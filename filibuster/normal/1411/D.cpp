#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;





/*

*/

li s0[N], p0[N], s1[N], p1[N];

int main() {
    string t;
    cin >> t;

    int x, y;
    cin >> x >> y;

    int n = t.size();

    int c0 = 0, c1 = 0, c2 = 0;;
    li ans = 0;
    for(int i = 0; i < n; i++) {
        if(t[i]== '0') {
            c0++;
            ans += y * 1ll * c1;
        } else if(t[i] == '1') {
            c1++;
            ans += x * 1ll * c0;
        } else {
            c2++;
        }

    }
//cout << ans << endl;
    if(!c0 || !c1) {
        cout<< 0 << endl;
        return 0;
    }

    if(c2 == 0) {
        cout << ans << endl;
        return 0;
    }


    li mn = 1e18;

    {
        int rg0 = c0, lf0 = 0, lf1 = 0, rg1 = c1;
        for(int i = 0; i < n; i++) {
            p0[i + 1] = p0[i];
            p1[i + 1] = p1[i];
            if(t[i] == '0') {
                lf0++;
                rg0--;
            } else if(t[i] == '1') {
                rg1--;
                lf1++;
            } else {
                p0[i + 1] += x * 1ll * rg1;
                p0[i + 1] += y * 1ll * lf1;
                p1[i + 1] += x * 1ll * lf0;
                p1[i + 1] += y * 1ll * rg0;

            }
        }
    }

    {
        int rg0 = 0, lf0 = c0, lf1 = c1, rg1 = 0;
        for(int i = n - 1; i >= 0; i--) {
            s0[i] = s0[i + 1];
            s1[i] = s1[i + 1];
            if(t[i] == '0') {
                lf0--;
                rg0++;
            } else if(t[i] == '1') {
                rg1++;
                lf1--;
            } else {
                s0[i] += x * 1ll * rg1;
                s0[i] += y * 1ll * lf1;
                s1[i] += x * 1ll * lf0;
                s1[i] += y * 1ll * rg0;

            }
        }
    }

    {
        int rg0 = c0, lf0 = 0, lf1 = 0, rg1 = c1;
        li res = 0;
        for(int i = 0; i < n; i++) {
            if(t[i] == '0') {
                lf0++;
                rg0--;
            } else if(t[i] == '1') {
                rg1--;
                lf1++;
            } else {
                li res1 = res + p1[i] + s0[i] + y * 1ll * (i - lf0 - lf1) * (n - i - rg0 - rg1);
//                cout << i << ' ' << res1 << ' ' << p1[i] << ' ' << s0[i] << endl;
                mn = min(mn, res1);
            }
        }
    }
//cout << mn << endl;
    {
        int rg0 = c0, lf0 = 0, lf1 = 0, rg1 = c1;
        li res = 0;
        for(int i = 0; i < n; i++) {
            if(t[i] == '0') {
                lf0++;
                rg0--;
            } else if(t[i] == '1') {
                rg1--;
                lf1++;
            } else {
                li res1 = res + p0[i] + s1[i] + x * 1ll * (i - lf0 - lf1) * (n - i - rg0 - rg1);
                mn = min(mn, res1);
            }
        }
    }
//cout << mn << endl;
    cout << ans + mn << endl;
}