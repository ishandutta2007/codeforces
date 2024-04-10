#include <iostream>
using namespace std;

int n;
int x [1000];
int bio [550] [550];

int rek (int l, int r)
{
    if (bio [l] [r]) return bio [l] [r];
    if (r - l < 2)
    {
        if (r == l) return 1;
        if (x [r] == x [l]) return 1;
        return 2;
    }
    int ret = 1000;
    if (x [l] == x [r]) ret = rek (l + 1, r - 1);
    for (int j = l; j < r; j++)
    {
        ret = min (ret, rek (l, j) + rek (j + 1, r));
    }
    return bio [l] [r] = ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x [i];
    }
    cout << rek(0, n - 1);
    return 0;
}