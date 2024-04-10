#include <iostream>
#include <sstream>

using namespace std;

int s[100001], l[100001], r = 0;
stringstream ss;

int main()
{
    int n, i, j, k = 0;
    s[0] = 0;
    l[0] = 0;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> j;
        if (j > s[r])
        {
            ++r;
            s[r] = j;
            l[r] = i;
            continue;
        }
        while (j < s[r])
        {
            ss << l[r] << ' ' << i - 1 << '\n';
            ++k;
            --s[r];
            if (s[r] == s[r - 1])
                --r;
        }
    }
    while (s[r] > 0)
    {
        ss << l[r] << ' ' << n << '\n';
        ++k;
        --s[r];
        if (s[r] == s[r - 1])
            --r;
    }
    cout << k << '\n' << ss.str();
    return 0;
}