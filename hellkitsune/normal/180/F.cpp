#include <iostream>

using namespace std;

const int maxln = 1e5 + 1;
int a[maxln], b[maxln], p[maxln];

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= n; ++i)
        p[a[i]] = b[i];
    for (int i = 1; i <= n; ++i)
        cout << p[i] << ' ';
    return 0;
}