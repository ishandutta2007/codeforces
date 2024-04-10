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

const int size = 5 * 1000 + 10;
char way[size][size];
int len, n, col[size], st[size];
bool flag;

void dfs(int v)
{
    int i;
    if (flag)
        return;
    col[v] = 1;
    st[len++] = v;
    //cerr << v << endl;
    //cerr << way[v] << endl;
    for (i = 0; i < n; i++)
        if (way[v][i] == '1' && col[i] == 1)
        {
            flag = true;
            printf("%d %d %d\n", i + 1, st[len - 2] + 1, v + 1);
            return;
        }
    for (i = 0; i < n; i++)
        if (way[v][i] == '1' && col[i] == 0)
        {
            dfs(i);
            if (flag)
                return;
        }
    len--;
    col[v] = 2;
    return;
}

int main()
{
    int i, j;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
        scanf("%s", way[i]);
    flag = false;
    len = 0;
    for (i = 0; i < n; i++)
        if (col[i] == 0)
            dfs(i);
    if (!flag)
        printf("-1\n");

    return 0;
}