#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int x = 0;
    for (auto c: s)
    {
        if (c == 'a')
        {
            x++;
        }
    }
    cout << min(2 * x - 1, (int)s.length()) << endl;
}