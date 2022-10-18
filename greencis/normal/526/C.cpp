#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;
typedef long long ll;

ll c,hr,hb,wr,wb,qqq;

ll f(ll x) {
    return x * hr + ((c - x * wr) / wb) * hb;
}

int main()
{
    cin >> c >> hr >> hb >> wr >> wb;
    ///while (cin >> qqq) cout << f(qqq) << endl;

    ll ans = 0ll;

    ll range = min(10000000ll, c / wr);
    for (ll i = 0; i <= range; ++i)
        ans = max(ans, max(f(i), f(c / wr - i)));

    for (int i = 0; i < 2; ++i) {
        swap(wr, wb), swap(hr, hb);
        ll L = 0ll, R = c / wr;
        while (L <= R) {
            if (R - L <= 10000000ll) {
                for (; L <= R; ++L) ans = max(ans, f(L));
            }
            ll mid1 = L + (R - L) / 3ll, mid2 = R - (R - L) / 3ll;
            if (f(mid1) < f(mid2)) L = mid1;
            else R = mid2;
        }
    }
    cout << ans;

    return 0;
}