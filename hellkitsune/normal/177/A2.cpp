#include <iostream>

using namespace std;

int n, a[101][101];
bool b[101][101] = {{false}};

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
    {
        b[i][i] = true;
        b[i][n - 1 - i] = true;
        b[n / 2][i] = true;
        b[i][n / 2] = true;
    }
    int answ = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (b[i][j])
                answ += a[i][j];
    cout << answ;
    return 0;
}