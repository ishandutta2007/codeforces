#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

const llong MOD = 998244353LL;

llong FastPow(llong k, llong p)
{
    if (p == 0)
        return 1LL;

    llong P = FastPow(k, p / 2LL);
    P = (P * P) % MOD;

    if (p % 2 == 1LL)
        P = (P * k) % MOD;

    return P;
}

llong Inv(llong k)
{
    return FastPow(k, MOD - 2);
}

int t;
int n;

llong invs[500111];

vector< pair<int, pair<int, int>> > Graph[500111];
vector<int> divs[500111];
bool isPrime[500111];

int topCount[500111];
int botCount[500111];
int maxCount[500111];

llong produceMax()
{
    llong ans = 1LL;
    int i, j;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=maxCount[i];j++)
        {
            ans *= (llong)i;
            ans %= MOD;
        }
    }

    return ans;
}

void refreshMax(int div)
{
    maxCount[div] = max(maxCount[div], botCount[div]);
}

void addTop(int div)
{
    //printf("top +%d\n", div);
    if (botCount[div] > 0)
        botCount[div]--;
    else
        topCount[div]++;
}

void addBot(int div)
{
    //printf("bot +%d\n", div);
    if (topCount[div] > 0)
        topCount[div]--;
    else
        botCount[div]++;

    refreshMax(div);
}

void addTops(int k)
{
    for (int i = 0; i < divs[k].size(); i++)
    {
        addTop(divs[k][i]);
    }
}

void addBots(int k)
{
    for (int i = 0; i < divs[k].size(); i++)
    {
        addBot(divs[k][i]);
    }
}

void DFS(int ver, int dad)
{
    //printf("Visiting %d\n", ver);

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        int nver = Graph[ver][i].first;
        int x = Graph[ver][i].second.first;
        int y = Graph[ver][i].second.second;

        if (nver == dad)
            continue;

        //printf("Entering %d from %d\n", nver, ver);
        addTops(x);
        addBots(y);
        //printf("Enter\n");
        DFS(nver, ver);
        //printf("Exiting %d to %d\n", nver, ver);
        addTops(y);
        addBots(x);
        //printf("Exited\n");
    }
}

llong compute(int ver, int dad, llong curVal)
{
    int i;
    llong total = curVal;

    for (i=0;i<Graph[ver].size();i++)
    {
        int nver = Graph[ver][i].first;
        llong x = Graph[ver][i].second.first;
        llong y = Graph[ver][i].second.second;

        if (nver == dad)
            continue;

        llong newVal = (curVal * x) % MOD;
        newVal = (newVal * invs[y]) % MOD;

        total += compute(nver, ver, newVal);
        if (total >= MOD)
            total -= MOD;
    }

    return total;
}

int main()
{
    int i, j;
    int test;

    for (i=2;i<=200000;i++)
    {
        isPrime[i] = true;
    }
    for (i=2;i<=200000;i++)
    {
        if (isPrime[i])
        {
            for (j=i;j<=200000;j+=i)
            {
                int cp = j;
                while(cp % i == 0)
                {
                    divs[j].push_back(i);
                    cp /= i;
                }

                isPrime[j] = false;
            }
        }
    }

    for (i=1;i<=200000;i++)
    {
        invs[i] = Inv(i);
    }

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=0;i<=n+1;i++)
        {
            topCount[i] = 0;
            botCount[i] = 0;
            maxCount[i] = 0;
            Graph[i].clear();
        }

        for (i=1;i<n;i++)
        {
            int a, b, x, y;

            scanf("%d %d %d %d", &a, &b, &x, &y);

            Graph[a].push_back(make_pair(b, make_pair(y, x)));
            Graph[b].push_back(make_pair(a, make_pair(x, y)));
        }

        DFS(1, 0);

        //printf("The maximal bot is %lld\n", produceMax());

        printf("%lld\n", compute(1, 0, produceMax()) % MOD);
    }

    return 0;
}