#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int x = 0, o = 0;
    string s[3];
    for (int i = 0; i < 3; ++i)
        cin >> s[i];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            if (s[i][j] == 'X')
                ++x;
            if (s[i][j] == '0')
                ++o;
        }
    if ((x > o + 1) || (x < o))
    {
        cout << "illegal" << endl;
        return 0;
    }
    bool first = x == o, md, sd, hl[3] = {false}, vl[3] = {false};
    int fw = 0, sw = 0;
    for (int i = 0; i < 3; ++i)
    {
        if ((s[i][0] == s[i][1]) && (s[i][1] == s[i][2]))
        {
            if (s[i][2] == 'X')
                ++fw;
            if (s[i][2] == '0')
                ++sw;
            if (s[i][2] != '.')
                hl[i] = true;
        }
        if ((s[0][i] == s[1][i]) && (s[1][i] == s[2][i]))
        {
            if (s[2][i] == 'X')
                ++fw;
            if (s[2][i] == '0')
                ++sw;
            if (s[2][i] != '.')
                vl[i] = true;
        }
    }
    if ((s[0][0] == s[1][1]) && (s[1][1] == s[2][2]))
    {
        if (s[2][2] == 'X')
            ++fw;
        if (s[2][2] == '0')
            ++sw;
        if (s[2][2] != '.')
            md = true;
    }
    if ((s[0][2] == s[1][1]) && (s[1][1] == s[2][0]))
    {
        if (s[2][0] == 'X')
            ++fw;
        if (s[2][0] == '0')
            ++sw;
        if (s[2][0] != '.')
            sd = true;
    }
    if ((fw && sw) || (fw && first) || (sw && !first))
    {
        cout << "illegal" << endl;
        return 0;
    }
    if (fw)
    {
        cout << "the first player won" << endl;
        return 0;
    }
    if (sw)
    {
        cout << "the second player won" << endl;
        return 0;
    }
    if (x + o == 9)
    {
        cout << "draw" << endl;
        return 0;
    }
    if (first)
        cout << "first" << endl;
    else
        cout << "second" << endl;
    return 0;
}