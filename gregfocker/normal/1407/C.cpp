#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rng((long long) (new char));
const int N = (int) 1e4 + 7;
int n;
int mx;
int a[N];

int ask(int i, int j)
{
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x;
    return x;
}

int big(int i, int j)
{
    int x = ask(i, j);
    int y = ask(j, i);
    if (y > x)
    {
        a[j] = y;
        return i;
    }
    else
    {
        a[i] = x;
        return j;
    }
}

int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << "! 1" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = -1;
    }
    int i = big(1, 2);
    for (int j = 3; j <= n; j++)
    {
        i = big(i, j);
    }
    a[i] = n;
    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}