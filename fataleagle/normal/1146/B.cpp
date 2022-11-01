#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, ss;
    cin >> s;
    int x = 0;
    for (auto c: s)
    {
        if (c != 'a')
        {
            ss += c;
        }
    }
    int n = ss.length();
    if (n % 2 == 0 && ss.substr(0, n/2) == ss.substr(n/2))
    {
        if (ss.substr(n/2) == s.substr(s.length() - n/2))
        {
            cout << s.substr(0, s.length() - n/2) << endl;
            return 0;
        }
    }
    cout << ":(\n";
}