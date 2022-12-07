#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string a, b;
    int c[10] = {0}, i, k;
    cin >> a >> b;
    for (i = 0; i < (int)b.length(); ++i)
        ++c[b[i] - '0'];
    k = 9;
    for (i = 0; i < (int)a.length(); ++i)
    {
        while (!c[k])
        {
            --k;
            if (!k)
            {
                cout << a;
                return 0;
            }
        }
        if (k > a[i] - '0')
        {
            a[i] = '0' + k;
            --c[k];
        }
    }
    cout << a;
    return 0;
}