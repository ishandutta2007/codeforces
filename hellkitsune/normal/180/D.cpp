#include <iostream>
#include <string>

using namespace std;

string s, t;
int a[26] = {0};
int n, m;
bool win = false;

bool go(int pos)
{
    if (win)
    {
        if (pos == n)
        {
            cout << s << endl;
            return true;
        }
        for (int i = 0; i < 26; ++i)
            if (a[i])
            {
                --a[i];
                s[pos] = i + 'a';
                go(pos + 1);
            }
        return true;
    }
    if (pos == n)
        return false;
    if (pos == m)
    {
        for (int i = 0; i < 26; ++i)
            if (a[i])
            {
                s[pos] = i + 'a';
                --a[i];
                win = true;
                go(pos + 1);
                return true;
            }
    }
    if (a[t[pos] - 'a'])
    {
        --a[t[pos] - 'a'];
        s[pos] = t[pos];
        if (go(pos + 1))
            return true;
        ++a[t[pos] - 'a'];
        for (int i = t[pos] + 1 - 'a'; i < 26; ++i)
            if (a[i])
            {
                win = true;
                --a[i];
                s[pos] = i + 'a';
                go(pos + 1);
                return true;
            }
        return false;
    }
    for (int i = t[pos] + 1 - 'a'; i < 26; ++i)
    if (a[i])
    {
        win = true;
        --a[i];
        s[pos] = i + 'a';
        go(pos + 1);
        return true;
    }
    return false;
}

int main(void)
{
    cin >> s >> t;
    n = s.length();
    m = t.length();
    for (int i = 0; i < n; ++i)
        ++a[s[i] - 'a'];
    if (!go(0))
        cout << -1 << endl;
    return 0;
}