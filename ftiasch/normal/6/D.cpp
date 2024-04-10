// Codeforces Beta Round #6
// Problem D -- Lizards and Basements 2
#include <iostream>

#define maxN 20
#define maxM 20
#define INF 99999

using namespace std;

int n, a, b, h[maxN], f[maxN][maxM][maxM];

int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++ i)
        cin >> h[i];
    for(int i = 0; i < maxM; ++ i)
        for(int j = 0; j < maxM; ++ j)
            f[0][i][j] = INF;
    f[0][0][0] = 0;
    for(int i = 1; i <= n; ++ i)
        for(int x_2 = 0; x_2 < maxM; ++ x_2)
            for(int x_3 = 0; x_3 < maxM; ++ x_3)
            {
                f[i][x_2][x_3] = INF;
                for(int x_1 = 0; x_1 < maxM; ++ x_1)
                    if(b * x_1 + a * x_2 + b * x_3 > h[i] && f[i - 1][x_1][x_2] + x_3 < f[i][x_2][x_3])
                        f[i][x_2][x_3] = f[i - 1][x_1][x_2] + x_3;
            }
    cout << f[n][0][0] << "\n";
    for(int i = n, x_2 = 0, x_3 = 0; i; -- i)
    {
        for(int j = 0; j < x_2; ++ j)
            cout << i << " ";
        for(int x_1 = 0; x_1 < maxM; ++ x_1)
            if(b * x_1 + a * x_2 + b * x_3 > h[i] && f[i - 1][x_1][x_2] + x_3 == f[i][x_2][x_3])
            {
                x_3 = x_2, x_2 = x_1;
                break;
            }
    }
    cout << "\n";
    return 0;
}