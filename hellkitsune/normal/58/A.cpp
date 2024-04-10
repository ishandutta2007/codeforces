#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string s, tmpl = "hello";
    int k = 0, i;
    cin >> s;
    for (i = 0; i < (int)s.length(); ++i)
        if (s[i] == tmpl[k])
        {
            ++k;
            if (k == 5)
            {
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
    return 0;
}