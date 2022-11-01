#include <bits/stdc++.h>
using namespace std;

inline int suma(int x)
{
    int ret = 0;
    while (x)
    {
        ret += x % 10;
        if (ret > 10) return 11;
        x /= 10;
    }
    return ret;
}

int n;

int main()
{
    cin >> n;
    int br = 1;
    for (int i = 0; i < n; i++)
    {
        while (suma (br) != 10)
        {
            br++;
        }
        br++;
    }
    cout << br - 1;
    return 0;
}