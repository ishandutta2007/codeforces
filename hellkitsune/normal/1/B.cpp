#include <iostream>
#include <string>

using namespace std;

string s;

void conv1(void)
{
    string t;
    int i;
    for (i = 1; s[i] != 'C'; ++i)
        t += s[i];
    int r = 0;
    for (++i; i < (int)s.length(); ++i)
        r = 10 * r + s[i] - '0';
    while (r)
    {
        t = char((r - 1) % 26 + 'A') + t;
        r = (r - 1) / 26;
    }
    s = t;
}

void conv2(void)
{
    string t = "R", t1;
    int i, r = 0;
    for (i = 0; s[i] > '9'; ++i)
        r = r * 26 + s[i] + 1 - 'A';
    for (; i < (int)s.length(); ++i)
        t += s[i];
    t += 'C';
    while (r)
    {
        t1 = char(r % 10 + '0') + t1;
        r /= 10;
    }
    s = t + t1;
}

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        bool flag = false, numb = false;
        cin >> s;
        for (int j = 0; j < (int)s.length(); ++j)
        {
            if ((s[j] >= '0') && (s[j] <= '9'))
                numb = true;
            else
            {
                if (numb)
                    flag = true;
            }
        }
        if (flag)
            conv1();
        else
            conv2();
        cout << s << endl;
    }
    return 0;
}