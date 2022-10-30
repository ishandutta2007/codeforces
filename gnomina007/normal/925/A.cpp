#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n, m, cl, ce, v;

    cin >> n >> m >> cl >> ce >> v;

    vector<int> l (cl), e (ce);

    for (auto &it : l)
        cin >> it;

    for (auto &it : e)
        cin >> it;

    int q;

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;

        cin >> y1 >> x1 >> y2 >> x2;

        int diff = abs (y1 - y2);

        if (x2 < x1)
            swap (x1, x2);

        int ans = numeric_limits<int>::max ();

        if (diff == 0)
            ans = x2 - x1;

        if (!l.empty ())
        {
            int wh = lower_bound (l.begin (), l.end (), x1) - l.begin ();

            if (wh == l.size () || wh > 0 && max (0, l[wh] - x2) > x1 - l[wh - 1])
                wh--;

            ans = min (ans, diff + x2 - x1 + max (0, 2 * max (l[wh] - x2, x1 - l[wh])));
        }

        if (!e.empty ())
        {
            int wh = lower_bound (e.begin (), e.end (), x1) - e.begin ();

            if (wh == e.size () || wh > 0 && max (0, e[wh] - x2) > x1 - e[wh - 1])
                wh--;

            ans = min (ans, (diff + v - 1) / v + x2 - x1 + max (0, 2 * max (e[wh] - x2, x1 - e[wh])));
        }

        cout << ans << endl;
    }
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}