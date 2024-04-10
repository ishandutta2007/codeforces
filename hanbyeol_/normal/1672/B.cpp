#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        string ans = "YES";
        if(s.back() == 'A') ans = "NO";
        int a = 0;
        for(char c: s)
        {
            if(c == 'A') ++a;
            else --a;
            if(a < 0) ans = "NO";
        }

        cout << ans << endl;
    }
}