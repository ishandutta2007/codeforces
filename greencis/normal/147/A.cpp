#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    int c;
    while ((c = getchar()) != -1) {
        if (c > ' ') {
            if (c == ',' || c == '.' || c == '!' || c == '?') {
                if (s[s.size() - 1] == ' ')
                    s[s.size() - 1] = c;
                else
                    s += c;
                s += " ";
            } else
                s += c;
        } else if (s[s.size() - 1] != ' ')
            s += ' ';
    }
    if (s[s.size() - 1] == ' ')
        s.erase(s.size() - 1, 1);
    cout << s;

    return 0;
}