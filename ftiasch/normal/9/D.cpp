// Codeforces Beta Round #9
// Problem D -- How many Trees?
#include <iostream>

using namespace std;

int n, h;
long long f[36][36];

int main()
{
    cin >> n >> h;
    for(int i = 0; i != 36; ++ i)
        f[0][i] = 1;
    for(int i = 1; i != 36; ++ i)
    {
        f[i][0] = 0;
        for(int j = 1; j != 36; ++ j)
        {
            f[i][j] = 0;
            for(int k = 0; k != i; ++ k)
                f[i][j] += f[k][j - 1] * f[i - 1 - k][j - 1];
        }
    }
    cout << f[n][35] - f[n][h - 1] << "\n";
    return 0;
}