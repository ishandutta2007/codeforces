#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int size = 1000;

int mr[size], ml[size];
char field[size][size];

int main()
{
    int n, m, i, j, pr, pc, w, ans;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d\n", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", field[i]);
    for (i = 0; i < n; i++)
    {
        mr[i] = -1;
        for (j = 0; j < m; j++)
            if (field[i][j] == 'W')
                mr[i] = j;
        ml[i] = m;
        for (j = m - 1; j >= 0; j--)
            if (field[i][j] == 'W')
                ml[i] = j;
    }
    //for (i = 0; i < n; i++)
    //    cerr << field[i] << endl;
    mr[n] = -1;
    ml[n] = m;
    while (n > 0 && mr[n - 1] == -1)
        n--;
    pr = 0;
    pc = 0;
    w = 0;
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }
    ans = 0;
    while (pr < n)
    {
       // cerr << pr << ' ' << pc << ' ' << ml[pr] << ' ' << mr[pr] << ' ' << w <<  endl;
        if (w == 0)
            if (pc < max(mr[pr], mr[pr + 1]))
                pc++;
            else
            {
                pr++;
                w ^= 1;
            }
        else
            if (pc > min(ml[pr], ml[pr + 1]))
                pc--;
            else
            {
                pr++;
                w ^= 1;
            }
        ans++;
    }
    printf("%d\n", ans - 1);

    return 0;
}