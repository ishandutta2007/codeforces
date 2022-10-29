#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;
char s[N];
int next_layer[11][11];
int a[11][11][11], b[11][11][11];
long long ans;
struct node{
    int lx, rx, idx;
    node(int LX = 0, int RX = 0, int IDX = 0)
    {
        lx = LX, rx = RX, idx = IDX;
    }
};
node nextnode(node a)
{
    return node((a.rx + 1) % 11, (a.rx + next_layer[a.lx][a.rx]) % 11, (a.rx + next_layer[a.lx][(a.idx + 10) % 11]) % 11);
}
int main()
{
    for (int i = 0; i < 11; i ++)
        for (int j = 0; j < 11; j ++)
        {
            int sum = i;
            int x = i;
            while (x != j)
            {
                x = (x + 1) % 11;
                (sum += x) %= 11;
            }
            next_layer[i][j] = sum;
        }
    scanf("%s", s);
    int len = strlen(s);
    for (int c = 0; c < len; c ++)
    {
        int x = s[c] - '0';
        for (int i = 0; i < 11;  i ++)
            for (int j = 0; j < 11; j ++)
                for (int k = 0; k < 11; k ++)
                    if (a[i][j][k] && k > x)
                    {
                        node u = nextnode(node(i, j, k));
                        (u.idx += x + 1) %= 11;
                        b[u.lx][u.rx][u.idx] += a[i][j][k];
                        ans += a[i][j][k];
                    }
        if (x)
            b[1][9][x] += 1, ans ++;
        for (int i = 0; i < 11; i ++)
            for (int j = 0; j < 11 ; j ++)
                for (int k = 0; k < 11; k ++)
                    a[i][j][k] = b[i][j][k], b[i][j][k] = 0;
    }
    cout << ans;
    return 0;
}