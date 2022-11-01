#include <bits/stdc++.h>
using namespace std;

int n, m, br0 = 0, br1 = 0, minl = -1e9, maxl = 1e9, minr = -1e9, maxr = 1e9;
int a [101000];
string b;

inline int maxi(int poz)
{
    int ret = -1e9;
    for (int neki = poz - 4; neki <= poz; neki++)
    {
        ret = max(ret, a [neki]);
    }
    return ret;
}

inline int mini(int poz)
{
    int ret = 1e9;
    for (int neki = poz - 4; neki <= poz; neki++)
    {
        ret = min(ret, a [neki]);
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a [i]);
    }
    cin >> b;
    br0 = 4;
    for (int i = 4; i < n; i++)
    {
        if (br0 >= 4)
        {
            if (b [i] == '0')
            {
                maxl = min(maxl, maxi(i));
            }
            else
            {
                minl = max(minl, maxi(i) + 1);
            }
        }
        else if (br1 >= 4)
        {
            if (b [i] == '1')
            {
                minr = max(minr, mini(i));
            }
            else
            {
                maxr = min(maxr, mini(i) - 1);
            }
        }
        if (b [i] == '0')
        {
            br1 = 0;
            br0++;
        }
        else
        {
            br0 = 0;
            br1++;
        }
    }
    cout << minl << " " << maxr << endl;
    return 0;
}