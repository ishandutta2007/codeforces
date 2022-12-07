#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    const int inf = 1000000;
    string s;
    cin >> s;
    int l, r, mx = -1, cur, c, i;
    for (l = 1; l < (int)s.length() - 1; ++l)
        for (r = l + 1; r < (int)s.length(); ++r)
        {
            cur = 0;
            if ((s[0] == '0') && (l > 1))
                continue;
            if ((s[l] == '0') && (r > l + 1))
                continue;
            if ((s[r] == '0') && (r != (int)s.length() - 1))
                continue;
            c = 0;
            for (i = 0; i < l; ++i)
            {
                c = c * 10 + s[i] - '0';
                if (c > inf)
                    c = inf + 1;
            }
            if (c > inf)
                continue;
            cur += c;
            c = 0;
            for (i = l; i < r; ++i)
            {
                c = c * 10 + s[i] - '0';
                if (c > inf)
                    c = inf + 1;
            }
            if (c > inf)
                continue;
            cur += c;
            c = 0;
            for (i = r; i < (int)s.length(); ++i)
            {
                c = c * 10 + s[i] - '0';
                if (c > inf)
                    c = inf + 1;
            }
            if (c > inf)
                continue;
            cur += c;
            if (cur > mx)
                mx = cur;
        }
    cout << mx;
    return 0;
}