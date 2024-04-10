#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
typedef long long llong;

llong MOD = 1000000007LL;
set<int> buy;
set<int> unknown;
set<int> sell;
set<int>::iterator myit;
int n;

int INF = 1000000000;

llong ANSWER = 1;

char command[21];

void setUnknown(int val)
{
    unknown.erase(val);

    for (myit=unknown.begin();myit!=unknown.end();myit++)
    {
        if ( (*myit) < val )
            buy.insert( (*myit) );
        else
            sell.insert( (*myit) );
    }

    unknown.clear();

    ANSWER *= 2;
    ANSWER %= MOD;

    return;
}

void printSet(set<int> ps)
{
    set<int>::iterator pi;

    printf("{");
    for (pi=ps.begin();pi!=ps.end();pi++)
    {
        printf("%d,",(*pi));
    }
    printf("}");
}

void flushToSell()
{
    for (myit=unknown.begin();myit!=unknown.end();myit++)
    {
        sell.insert( (*myit) );
    }
    unknown.clear();
}

void flushToBuy()
{
    for (myit=unknown.begin();myit!=unknown.end();myit++)
    {
        buy.insert( (*myit) );
    }
    unknown.clear();
}

int main()
{
    int i;
    int val;
    int maxBuy,minSell;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s",command);
        scanf("%d",&val);

        if (command[1] == 'C')
        {
            if (!buy.empty())
            {
                myit = buy.end();
                myit--;
                maxBuy = (*myit);

                if (val == maxBuy)
                {
                    buy.erase(val);
                    flushToSell();
                    continue;
                }
                else if (buy.find(val) != buy.end())
                {
                    printf("0\n");
                    return 0;
                }
            }

            if (!sell.empty())
            {
                myit = sell.begin();
                minSell = (*myit);

                if (val == minSell)
                {
                    sell.erase(val);
                    flushToBuy();
                    continue;
                }
                else if (sell.find(val) != sell.end())
                {
                    printf("0\n");
                    return 0;
                }
            }

            setUnknown(val);
        }
        else
        {
            maxBuy = -INF;
            if (!buy.empty())
            {
                myit = buy.end();
                myit--;
                maxBuy = (*myit);
            }

            minSell = INF;
            if (!sell.empty())
            {
                myit = sell.begin();
                minSell = (*myit);
            }

            if (val <= maxBuy)
                buy.insert(val);
            else if (val >= minSell)
                sell.insert(val);
            else
                unknown.insert(val);
        }
    }

    ANSWER *= ((llong)(unknown.size()) + 1LL);
    ANSWER %= MOD;

    printf("%lld\n",ANSWER);

    return 0;
}