#include <iostream>

using namespace std;

int n, a[1000000], mnu = 1;
bool used[1000000] = {}, u[1000000] = {};

int rec()
{
    while (used[mnu]) mnu++;
    used[mnu] = true;
    return mnu;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if ((a[i] <= n) && (!used[a[i]]))
        {
            u[i] = true;
            used[a[i]] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!u[i]) a[i] = rec();
        cout << a[i] << " ";
    }
}