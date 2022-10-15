#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b; cin >> a >> b;
    int n = a.length();
    int dif = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) dif++;
    if (dif % 2 == 0)
    {
        dif /= 2;
        for (int i = 0; i < n; i++)
            if (dif > 0 && a[i] != b[i])
            {
                a[i] = b[i];
                dif--;
            }
        cout << a;
    }
    else cout << "impossible";
}