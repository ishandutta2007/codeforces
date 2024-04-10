#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>

#define PB push_back

using namespace std;

vector<int> next[100000 + 7];
int t[100000 + 7];
bool v[100000 + 7];
long long w[100000 + 7];
long long vv[100000+7];
long long pack[2][77777 + 3];
int N;
int amount;

long long min(long long a,long long b) {return a < b?a :b;}

void dfs(int u)
{
    ++amount;
    v[u] = true;
    for (int i = 0;i < next[u].size();++i)
        if (!v[next[u][i]])
            dfs(next[u][i]);
}

int main()
{
    memset(t,0,sizeof(t));
    memset(v,0,sizeof(v));
    int n,m;
    cin >> n >> m;
    for (int i = 0;i < n;++i)
        next[i].clear();
    for (int a,b,i = 0;i < m;++i)
    {
        cin >> a >> b;
        next[--a].PB(--b);
        next[b].PB(a);
    }
    for (int i = 0;i < n;++i)
        if (!v[i])
        {
            amount = 0;
            dfs(i);
            t[amount]++;
        }
    N = 0;
    for (int i = 1;i <= n;++i)
    {
        if (t[i] == 0) continue;
        int base = 1;
        while (t[i] >= base)
        {
            t[i] -= base;
            w[++N] = (long long)i * base;
            vv[N] = base;
            base <<= 1;
        }
        if (t[i] > 0)
        {
            w[++N] = (long long)i * t[i];
            vv[N] = t[i];
        }

    }
    memset(pack,0x7f,sizeof(pack));
    pack[0][0] = 0;
    for (int i = 1;i <= N;++i)
    {
        memset(pack[i&1],0x7f,sizeof(pack[i&1]));
        for (int j = 0;j <= min(n,77777);++j)
        {
            pack[i&1][j] = pack[(i-1)&1][j];
            if (j - w[i] >= 0)
                pack[i&1][j] = min(pack[i&1][j],pack[(i-1)&1][j-w[i]]+vv[i]);
        }
    }
    int ans = 0x7fffffff;
    for (int i = 1;i <= n;++i)
    {
        bool check = true;
        int ii = i;
        while (ii > 0)
        {
            if (ii % 10 != 4 && ii % 10 != 7)
            {
                check = false;
                break;
            }
            ii /= 10;
        }
        if (check)
            ans = min(ans,pack[N&1][i]-1);
    }
    if (ans > n)
        ans = -1;
    cout << ans << endl;
    return 0;
}