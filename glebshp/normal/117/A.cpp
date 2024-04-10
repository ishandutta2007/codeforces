#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

int main()
{
    long long n, m, fs, fe, t, d, ans;
    int i;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    m--;
    for (i = 0; i < n; i++)
    {
        cin >> fs >> fe >> t;
        if (fs == fe)
            cout << t << endl;
        else
        {
            d = t % (m * 2);
            ans = t;
            if (fe > fs)
            {
                if (d > fs - 1)
                    ans += (m * 2 - d) + fs - 1;
                else
                    ans += (fs - d - 1);
                ans += (fe - fs);
            }
            else
            {
                if (d <= m * 2 - fs + 1)
                    ans += - d - fs + 2 * m + 1;
                else
                    ans += (m * 2 - d + m + m - fs + 1);
                ans += (fs - fe);
            }
            cout << ans << endl;
        }
    }

    return 0;
}