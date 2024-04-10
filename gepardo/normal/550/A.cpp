#include <iostream>
#include <string>

using namespace std;

int sa[100000], sb[100000];
int ac, bc, p;

int main()
{
    string s; cin >> s; int n = s.length();
    p = s.find("AB"); while (p != string::npos) ac++, sa[p] = true, p = s.find("AB", p + 1);
    p = s.find("BA"); while (p != string::npos) bc++, sb[p] = true, p = s.find("BA", p + 1);
    if (bc == 0 || ac == 0) { cout << "NO"; return 0; }
    for (int i = 0; i < (n - 1); i++)
    {
        bool pre = (i == 0) ? false : sb[i - 1];
        if (sa[i])
        {
            if (!(sb[i + 1] || pre) || bc > (sb[i + 1] + pre))
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}