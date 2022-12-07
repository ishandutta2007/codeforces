#include <iostream>

using namespace std;

const int maxln = 1e5;
int n, m, c;
int a[maxln], b[maxln];

int main(void)
{
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    int l = 0, r = 0, toadd = b[0];
    for (int i = 0; i < n; ++i)
    {
        if (i > n - m)
            toadd -= b[l++];
        cout << (a[i] + toadd) % c << ' ';
        if (i < m - 1)
            toadd += b[++r];
    }
    cout << endl;
    return 0;
}