#include <iostream>

using namespace std;

int d, st, st2 = 0, a[30], b[30];

int main(void)
{
    cin >> d >> st;
    for (int i = 0; i < d; ++i)
        cin >> a[i] >> b[i];
    for (int i = 0; i < d; ++i)
    {
        st -= a[i];
        st2 += b[i] - a[i];
    }
    if ((st < 0) || (st > st2))
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < d; ++i)
    {
        if (st > b[i] - a[i])
        {
            cout << b[i] << ' ';
            st -= b[i] - a[i];
        }
        else
        {
            cout << a[i] + st << ' ';
            st = 0;
        }
    }
    return 0;
}