#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int a = 0, b = 0, na, nb;
    for (int i = 0; i < (int)s.length(); ++i)
    {
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            na = a;
            nb = min(a, b) + 1;
        }
        else
        {
            na = a + 1;
            nb = min(a, b);
        }
        a = na;
        b = nb;
    }
    cout << min(a, b) << endl;
    return 0;
}