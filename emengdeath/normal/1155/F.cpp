#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;
const int N = 14;
int n,  m;
bool can[1 << N][N][N];
int can_from[1<<N][N][N], step[1 << N];
pair<int, int>help[1 << N];
vector<int>g[N];
struct node{
    int step;
    int from_x, from_st, from_en;
}f[1<<N];
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i < (1 << n) ; i ++)
    {
        int sum = 0;
        int x = i;
        while (x) sum += (x & 1), x >>= 1;
        step[i] = sum - 1;
    }
    for (int i = 0; i < n ; i ++)
        for (int j = i; j < n ; j ++)
            help[(1 << i)|(1 << j)] = make_pair(i, j);
    for (int i = 1; i <= m ; i ++){
        int x, y;
        scanf("%d %d", &x, &y);
        x --;
        y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < (1 << n);  i ++)
        f[i].step  = 1e9;
    for (int i = 0; i < n ; i ++)
        can[1 << i][i][i] = 1, f[1 << i].step = 0;
    for (int i = 1; i < (1 << n); i ++)
        for (int st = 0 ; st < n ; st ++) {
            for (int en = 0; en < n; en++)
                if (can[i][st][en] && !(st == en && step[i]))
                    for (auto to : g[en])
                        if ((!(i & (1 << to)))||(st == to)) {
                            if (!can[i | (1 << to)][st][to]) {
                                if (st == to && step[i | (1 << to)] < 2) continue;
                                can[i | (1 << to)][st][to] = 1;
                                can_from[i | (1 << to)][st][to] = en;
                            }
                        }
        }
    for (int i = 1 ; i < (1 << n) ; i ++)
        if (f[i].step < m)
            for (int j = 1 ; j < (1 << n); j ++)
                if ((i & j) && step[i & j] <= 1)
                {
                    int st = help[i & j].first;
                    int en = help[i & j].second;
                    if (can[j][st][en])
                    {
                        if (f[i].step + step[j] + (st == en) < f[i|j].step)
                        {
                            f[i|j].step = f[i].step + step[j] +  (st == en);
                            f[i|j].from_st = st;
                            f[i|j].from_en = en;
                            f[i|j].from_x = i;
                        }
                    }
                }
    printf("%d\n", f[(1 << n) - 1].step);
    int x = (1 << n) - 1;
    while (step[x])
    {
        int st = f[x].from_st;
        int en = f[x].from_en;
        int v = x - f[x].from_x;
        v |= ((1 << st) | (1 << en));
        while (step[v])
        {
            printf("%d %d\n", can_from[v][st][en] + 1, en + 1);
            int vv = v - (1 << en);
            vv |= (1 << st);
            en = can_from[v][st][en];
            v = vv;
        }
        x = f[x].from_x;
    }
    return 0;
}