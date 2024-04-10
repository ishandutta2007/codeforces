#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long llong;

const llong MOD = 1000000007LL;
int t;
int n,p;
int k[2000111];

llong fastPow(llong NUM, llong POWER)
{
    if (POWER == 0)
        return 1LL;

    llong MID = fastPow(NUM, POWER / 2);

    MID = (MID * MID) % MOD;

    if (POWER % 2 == 1)
        MID = (MID * NUM) % MOD;

    return MID;
}

int clearup(int ind, int val)
{
    int i;
    vector< pair<int,int> > vals;

    for (i=ind;i>=1;i--)
    {
        if (!vals.empty() && vals.back().first == k[i])
            vals.back().second++;
        else
            vals.push_back(make_pair(k[i], 1));

        while(!vals.empty() && vals.back().second == p)
        {
            int newadd = vals.back().first + 1;
            vals.pop_back();

            if (vals.empty() || vals.back().first != newadd)
                vals.push_back(make_pair(newadd, 1));
            else
                vals.back().second++;
        }

        if (vals[0].first == val)
            return i;
    }

    return -1;
}

int main()
{
    //freopen("test.txt", "r", stdin);

    int i,j;
    int test;
    llong ans;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d",&n,&p);

        for (i=1;i<=n;i++)
        {
            scanf("%d",&k[i]);
        }

        if (p == 1)
        {
            if (n % 2 == 0)
            {
                printf("0\n");
            }
            else
            {
                printf("1\n");
            }

            continue;
        }

        sort(k+1,k+1+n);

        int cur = n;

        ans = 0;
        while(cur >= 1)
        {
            ///Taking cur
            int clearInd = clearup(cur-1, k[cur]);

            //cout<<"Cleaning "<<k[cur]<<" takes all from "<<clearInd<<" to "<<cur-1<<endl;

            if (clearInd == -1) ///Diff ending
            {
                ans = fastPow(p, k[cur]);

                for (i=cur-1;i>=1;i--)
                {
                    ans -= fastPow(p, k[i]);
                    if (ans < 0)
                        ans += MOD;
                }

                break;
            }

            cur = clearInd - 1;
        }

        printf("%lld\n", ans);
    }

    return 0;
}