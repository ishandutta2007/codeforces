#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int k, l, j;
    long long z;
    unsigned i;
    long long answ = 0;
    bool flag = false;
    string s;
    cin >> k >> s;
    if (!k)
    {
        z = 0;
        for (i = 0; i < s.length(); ++i)
        {
            if (s[i] == '1')
            {
                answ += (z * (z + 1)) / 2;
                z = 0;
            }
            if (s[i] == '0')
                ++z;
        }
        answ += (z * (z + 1)) / 2;
        cout << answ;
        return 0;
    }
    l = 0;
    for (i = 0; i < s.length(); ++i)
    {
        if (flag)
        {
            if (s[i] == '1')
            {
                j = 0;
                while (s[l++] != '1')
                    ++j;
                answ += (long long)(j + 1) * (long long)(k + 1);
                k = 0;
            }
            if (s[i] == '0')
            {
                ++k;
            }
        }
        else
        {
            if (s[i] == '1')
                --k;
            if (k == 0)
            {
                flag = true;
                l = 0;
            }
        }
    }
    if (flag)
    {
        j = 0;
        while (s[l++] != '1')
            ++j;
        answ += (long long)(j + 1) * (long long)(k + 1);
        k = 0;
    }
    cout << answ;
    return 0;
}