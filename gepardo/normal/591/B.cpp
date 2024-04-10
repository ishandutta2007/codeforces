#include <iostream>
#include <cstdio>

using namespace std;

char getchr()
{
    char c = 0;
    while (c < 33) c = getchar();
    return c;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    getline(cin, s);
    getline(cin, s);
    char l[26];
    for (int i = 0; i < 26; i++) l[i] = i + 'a';
    for (int i = 0; i < m; i++)
    {
        char a = getchr(), b = getchr();
        for (int j = 0; j < 26; j++)
            if (l[j] == a) l[j] = b; else if (l[j] == b) l[j] = a;
    }
    for (int i = 0; i < n; i++)
        cout << l[s[i] - 'a'];
}