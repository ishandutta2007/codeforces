#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int INF = 1e8;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int h, c, t;
        cin >> h >> c >> t;
        if (t * 2 <= c + h) {
            cout << 2 << endl;
            continue;
        }   
        if (t >= h) {
            cout << 1 << endl;
            continue;
        }   

        int l = 1;
        int r = INF;
        while (l < r - 1) {
            int m = (l + r) >> 1;
            /*
            if ( (h+c)/2 + (h - (h+c)/2) / (2 * m - 1) > t)
                l = m;
            else
                r = m;
            */
            if ((h+c) * (2 * m - 1) + h * 2 - (h+c) > t * (2 * m - 1) * 2)
                l = m;
            else
                r = m;
        }   

        ii a = {(h + c) * (2 * l - 1) + h * 2 - (h + c) - t * (2 * l - 1) * 2, (2 * l - 1) * 2};
        ii b = {(h + c) * (2 * r - 1) + h * 2 - (h + c) - t * (2 * r - 1) * 2, (2 * r - 1) * 2};
        b.f = -b.f;

        /*
        #ifdef HOME
        cout << l << ' ' << r << endl;
        cout << "a : " << a.f << ' ' << a.s << endl;
        cout << "b : " << b.f << ' ' << b.s << endl;
        #endif
        */

        if (a.f * b.s <= b.f * a.s) {
            cout << 2 * l - 1 << endl;
        }   
        else {
            cout << 2 * r - 1 << endl;
        }   
    }   
}