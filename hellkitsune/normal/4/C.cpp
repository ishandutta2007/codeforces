#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, k;
map<string, int> m;
string s;

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        if ((k = m[s]++) > 0)
            cout << s << k << endl;
        else
            cout << "OK" << endl;
    }
    return 0;
}