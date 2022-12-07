#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string s = "", t;

void sremove()
{
    int k = -1;
    for (int i = 0; i < (int)s.length(); ++i)
        if (s[i] != ' ')
            s[++k] = s[i];
    s.erase(k + 1);
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    bool sempt = true;
    while (!feof(stdin))
    {
        getline(cin, t);
        bool flag = false;
        for (int i = 0; i < (int)t.length(); ++i)
            if (t[i] != ' ')
            {
                if (t[i] == '#')
                    flag = true;
                break;
            }
        if (flag)
        {
            if (sempt)
                cout << t << '\n';
            else
            {
                sremove();
                cout << s << '\n' << t << '\n';
            }
            s = "";
            sempt = true;
        }
        else
        {
            s.append(t);
            if (!sempt)
                s.append(" ");
            sempt = false;
        }
    }
    if ((!sempt) && (s != ""))
    {
        sremove();
        cout << s << '\n';
    }
    return 0;
}