#include <bits/stdc++.h>
using namespace std;

int n;
int l [5100];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &l [i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int a = l [i];
        int b = l [a];
        int c = l [b];
        if (c == i)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}