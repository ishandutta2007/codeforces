#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

int n, m;
ll same(vector<ll> a, vector<ll> b)
{
    vector<ll> da(m + 1, 0), db(m + 1, 0);
    ll oa = 0, ob = 0;
    for (int i = 0; i + 1 < m; i++)
    {
        oa += da[i], ob += db[i];
        ll k = min(oa, a[i + 1]);
        a[i] += k;
        oa -= k;
        a[i + 1] -= k;
        k = min(ob, b[i + 1]);
        b[i] += k;
        ob -= k;
        b[i + 1] -= k;
        k = abs(a[i] - b[i]);
        if (a[i] > b[i]) a[i] -= k, a[i + 1] += k, da[i + 2] += k;
        if (a[i] < b[i]) b[i] -= k, b[i + 1] += k, db[i + 2] += k;
    }
    oa += da[m - 1] + da[m], ob += db[m - 1] + db[m];
    return abs(oa - ob);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<ll> > v(n, vector<ll>(m));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];
        int d = -1;
        for (int i = 1; i < n; i++)
        {
            if (same(v[0], v[i]) != 0)
            {
                int j = (i == 1) ? 2 : 1;
                if (same(v[j], v[i]) == 0) d = 0;
                else d = i;
            }
        }
        int i = (d == 0) ? 1 : 0;
        //cout << "               ";
        cout << d + 1 << " " << same(v[i], v[d]) << "\n";
    }
    return 0;
}