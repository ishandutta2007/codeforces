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

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void cook (const string &str, vector<int> &a, vector<int> &bc)
{
    a.resize (str.size () + 1);
    bc.resize (str.size () + 1);

    for (int i = 1; i < a.size (); i++)
    {
        assert ('A' <= str[i - 1] && str[i - 1] <= 'C');

        if (str[i - 1] == 'A')
            a[i] = a[i - 1] + 1;

        bc[i] = bc[i - 1] + (str[i - 1] == 'A' ? 0 : 1);
    }
}

bool check (int sa, int sb, int ta, int tb)
{
    if (sb % 2 != tb % 2)
        return false;

    if (tb < sb)
        return false;

    if (sb == tb)
        return sa >= ta && sa % 3 == ta % 3;

    return sb == 0 ? sa > ta : sa >= ta;
}

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    string s, t;

    cin >> s >> t;

    int q;

    cin >> q;

    string ans;
    ans.reserve (q);

    vector<int> sa, sbc;
    vector<int> ta, tbc;

    cook (s, sa, sbc);
    cook (t, ta, tbc);

    for (int t = 0; t < q; t++)
    {
        int a, b, c, d;

        cin >> a >> b >> c >> d;
        a--;
        c--;

        int sb = sbc[b] - sbc[a];
        int tb = tbc[d] - tbc[c];
        int sas = min (sa[b], b - a);
        int sat = min (ta[d], d - c);

        ans += check (sas, sb, sat, tb) ? '1' : '0';
    }

    cout << ans << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}