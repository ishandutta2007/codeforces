#include <iostream>

using namespace std;

const int mn = (int)2e5;
int a[mn], b[mn], c[mn], n;

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        --b[i];
    }
    for (int i = 0; i < n; ++i)
        c[b[i]] = i;
    for (int i = 0; i < n; ++i)
        a[i] = c[a[i]];
    int ans = 0;
    for (int i = n - 2; i >= 0; --i)
        if (a[i] > a[i + 1])
            ans = n - i - 1;
    cout << ans << endl;
    return 0;
}