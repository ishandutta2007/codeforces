#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n; cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        int q = s.length();
        bool first = true;
        int p = 0;
        if (s[0] == 'R')
        {
            string u;
            for (int i = 1; i < q; i++)
            {
                if (i == q - 1)
                {
                    first = false;
                    break;
                }
                if (s[i] == 'C')
                {
                    if (i == 1) first = false;
                    p = i;
                    break;
                }
                if (s[i] < '0' || s[i] > '9')
                {
                    first = false;
                    break;
                }
                u += s[i];
            }
            if (first)
            {
                string w;
                for (int i = p + 1; i < q; i++) w += s[i];
                istringstream e(w);
                int y;
                e >> y;
                y--;
                int p = 26, l = 1;
                while (y > p)
                {
                    y -= p;
                    p *= 26;
                    l++;
                }
                string t;
                for (int i = 0; i < l; i++)
                {
                    t = string("") + char('A' + y % 26) + t;
                    y /= 26;
                }
                cout << t << u << endl;
            }
        }
        else first = false;
        if (!first)
        {
            string u, w;
            int p;
            for (int i = 0; i < q; i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    p = i;
                    break;
                }
                u += s[i];
            }
            for (int i = p; i < q; i++) w += s[i];
            int b = 1;
            p = 26;
            for (int i = 1; i < u.length(); i++)
            {
                b += p;
                p *= 26;
            }
            int y = 0;
            for (int i = 0; i < u.length(); i++)
                y = y * 26 + (u[i] - 'A');
            cout << "R" << w << "C" << y + b << endl;
        }
    }
}