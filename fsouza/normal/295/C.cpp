#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>

#define MAXN 51
#define INF 1000000000

typedef long long lint;

using namespace std;

const lint mod = 1000000007;

int n, maxweight;
int tot50, tot100;
pair <int, lint> dp[MAXN+1][MAXN+1][2*MAXN+4][2];
int mark[MAXN+1][MAXN+1][2*MAXN+4][2];
lint choose[MAXN+1][MAXN+1];

pair <int, lint> get(int l50, int l100, int depth, int side)
{
    const int r50 = tot50-l50;
    const int r100 = tot100-l100;

    if (side == 1 && l50 == 0 && l100 == 0)
        return make_pair(0, 1);
    
    if (depth > 2*n+3)
        return make_pair(INF, 0);

    pair <int, lint>& ret = dp[l50][l100][depth][side];
    if (mark[l50][l100][depth][side]) return ret;

    ret = make_pair(INF, 0);
    mark[l50][l100][depth][side] = 1;

    const int max50 = (side == 0) ? l50 : r50;
    const int max100 = (side == 0) ? l100 : r100;
    for (int x50 = 0; x50 <= max50; x50++)
        for (int x100 = 0; x100 <= max100; x100++) {
            if ((x50 == 0 && x100 == 0) || 50*x50 + 100*x100 > maxweight)
                continue;

            int newl50 = l50, newl100 = l100;
            if (side == 0) {
                newl50 -= x50;
                newl100 -= x100;
            } else {
                newl50 += x50;
                newl100 += x100;
            }

            pair <int, lint> res = get(newl50, newl100, depth + (side == 1), side^1);
            res.first += 1;

            if (res.first <= ret.first) {
                if (res.first < ret.first) {
                    ret.first = res.first;
                    ret.second = 0;
                }
                
                lint many = res.second;
                many = (many * choose[max50][x50])%mod;
                many = (many * choose[max100][x100])%mod;

                ret.second = (ret.second + many)%mod;
            }
        }

    return ret;
}

void precalc_binoms()
{
    int maxn = MAXN;

    for (int i = 0; i <= maxn; i++)
        choose[i][0] = choose[i][i] = 1;

    for (int i = 2; i <= maxn; i++)
        for (int j = 1; j < i; j++)
            choose[i][j] = (choose[i-1][j] + choose[i-1][j-1])%mod;
}

int main()
{
    precalc_binoms();

    tot50 = tot100 = 0;

    scanf("%d %d", &n, &maxweight);
    
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        if (v == 50) tot50++;
        else tot100++;
    }

    memset(mark, 0, sizeof(mark));

    pair <int, lint> ret = get(tot50, tot100, 0, 0);

    if (ret.first == INF)
        printf("-1\n0\n");
    else
        printf("%d\n%d\n", ret.first, (int)ret.second);

    return 0;
}