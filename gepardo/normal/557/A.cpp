#include <iostream>

using namespace std;

int n, l1, l2, l3, m1, m2, m3, a1, a2, a3;

void ans()
{
    a1 = m1; a2 = m2; a3 = m3;
    int s = a1 + a2 + a3;
    if (s > n)
    {
        s -= (m3 - l3);
        a3 = l3;
        if (s < n)
        {
            a3 += (n - s);
            return;
        }
    }
    if (s > n)
    {
        s -= (m2 - l2);
        a2 = l2;
        if (s < n)
        {
            a2 += (n - s);
            return;
        }
    }
    if (s > n)
    {
        s -= (m1 - l1);
        a1 = l1;
        if (s < n)
        {
            a1 += (n - s);
            return;
        }
    }
}

int main()
{
    cin >> n >> l1 >> m1 >> l2 >> m2 >> l3 >> m3;
    if (m1 > n) m1 = n;
    if (m2 > n) m2 = n;
    if (m3 > n) m3 = n;
    ans();
    cout << a1 << " " << a2 << " " << a3;
}