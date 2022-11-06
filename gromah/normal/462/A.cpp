#include <cstdio>
#include <iostream>
using namespace std;

const int Fx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, F[102][102];

int main()
{
    scanf("%d", &n);
    char ch = getchar();
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            while (ch != 'o' && ch != 'x')
                ch = getchar();
            F[i][j] = ch == 'o' ? 1 : 0;
            ch = getchar();
        }
    bool ok = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
        {
            int cnt = 0;
            for (int k = 0; k < 4; k ++)
            {
                int tx = i + Fx[k][0], ty = j + Fx[k][1];
                cnt += F[tx][ty];
            }
            if (cnt & 1) ok = 0;
        }
    if (ok) puts("YES");
        else puts("NO");
    return 0;
}