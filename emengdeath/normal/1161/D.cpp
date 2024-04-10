#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
using namespace std;
const int N = 3001;
const int mod = 998244353;
char s[N];
bool bz[N];
int belong[N];
long long ans;
bool sig01;
int n;
vector<int>g0[N], g1[N],g;
long long calc(long long x, long long y)
{
    long long z = 1;
    while (y)
    {
        if (y & 1) (z *= x) %= mod;
        (x *= x) %= mod, y /= 2;
    }
    return z;
}
void dfs(int x)
{
    if (belong[x]) return;
    belong[x]  = belong[0];
    g.push_back(x);
    for (auto u:g0[x])
        dfs(u);
}
void dfs1(int x, int i)
{
    if (bz[x]) return;
    if (x == (n + i +  1) || x == (n + i + 2))
        sig01 = 1;
    bz[x] = 1;
    for (auto u:g0[x])
        dfs1(u, i);
    for (auto u:g1[x])
        dfs1(u, i);
}

bool dfs2(int x, int tag)
{
    if (belong[x]) return belong[x] == tag;
    belong[x] = tag;
    for (auto u:g0[x])
        if (!dfs2(u, tag))
            return 0;
    tag = tag % 2 + 1;
    for (auto u:g1[x])
        if (!dfs2(u, tag))
            return 0;
    return 1;
}
int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i < n ; i ++)
    {
        for (int j = 1; j <= n + 2 + i; j ++)
            g0[j].clear(), g1[j].clear();
        g1[n + i + 1].push_back(n + i + 2);
        g1[n + i + 2].push_back(n + i + 1);
        g0[n + 1].push_back(n + i + 2);
        g0[n + i + 2].push_back(n + 1);
        g0[n + i].push_back(n + i + 2);
        g0[n + i + 2].push_back(n + i);
        for (int j = 1; j <=  i  / 2; j ++) {
            g0[n + j].push_back(n + (i - j + 1));
            g0[n + (i -  j + 1)].push_back(n + j);
        }
        for (int j = 1; j <= (n) / 2; j ++)
        {
            g0[j].push_back(n - j + 1);
            g0[n - j + 1].push_back(j);
        }
        for (int j = 1; j <= n - i ; j ++)
            if (s[j] == '1')
            {
                g0[j].push_back(n + i + 2);
                g0[n + i + 2].push_back(j);
            } else
                if (s[j] == '0')
                {
                    g0[j].push_back(n + i + 1);
                    g0[n + i + 1].push_back(j);
                }
        for (int j = 1; j <= i ; j ++)
        {
            int x = n - (i - j);
            if (s[x] == '1') {
                g1[x].push_back(n + j);
                g1[n + j].push_back(x);
            } else
            if (s[x] == '0')
            {
                g0[x].push_back(n + j);
                g0[n + j].push_back(x);
            }
        }
        for (int j = 0; j <= n + i  + 2; j ++)
            belong[j] = bz[j] = 0;
        bool sig = 1;
        for (int j = 1;j <= n + i + 2 && sig;  j++)
            if (!belong[j])
            {
                g.clear();
                belong[0] ++;
                dfs(j);
                for (auto u:g) {
                    for (auto v:g1[u])
                        if (belong[v] && belong[v] == belong[u]) {
                            sig = 0;
                            break;
                        }
                    if (!sig) break;
                }
            }
        if (!sig) continue;
        int cnt = 0;
        for (int j  =1; j <= n + i + 2; j ++)
            if (!bz[j])
                sig01 = 0, dfs1(j, i), cnt += (!sig01);

        for (int j = 0; j <= n + i  + 2; j ++)
            belong[j] = bz[j] = 0;
        for (int j = 1 ; j <= n + i + 2 && sig; j ++)
            if (!belong[j])
                if (!dfs2(j, 1)) sig = 0;
        if (!sig) continue;
        (ans += calc(2, cnt)) %= mod;
    }
    printf("%d\n", ans);
    return 0;
}