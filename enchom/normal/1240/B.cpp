#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

const int INF = 1000000000;

int MIN(int a,int b)
{
    if (a < b)
        return a;
    else
        return b;
}


int t;
int n;
vector<int> nums[300111];

vector<int> present;
int firstv[300111];

int IT[1200111];
int LEAFOFFSET;

void setVal(int ind, int val)
{
    ind += LEAFOFFSET;
    IT[ind] = val;
    ind /= 2;

    while(ind > 0)
    {
        IT[ind] = MIN(IT[2*ind], IT[2*ind+1]);
        ind /= 2;
    }
}

int getMin(int L, int R)
{
    L += LEAFOFFSET;
    R += LEAFOFFSET;
    int ans = MIN(IT[L], IT[R]);

    while(R - L > 1)
    {
        if (L % 2 == 0)
            ans = MIN(ans, IT[L+1]);
        if (R % 2 == 1)
            ans = MIN(ans, IT[R-1]);
        L /= 2;
        R /= 2;
    }

    return ans;
}

bool dangerous(int v)
{
    return getMin(firstv[v], n) < v;
}

int main()
{
    int test;
    int i,j;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);

        LEAFOFFSET = 1;
        while(LEAFOFFSET < n)
            LEAFOFFSET *= 2;
        LEAFOFFSET--;

        for (i=1;i<=2*LEAFOFFSET+1;i++)
        {
            IT[i] = INF;
        }
        for (i=1;i<=n;i++)
        {
            nums[i].clear();
        }

        for (i=1;i<=n;i++)
        {
            int a;

            scanf("%d",&a);

            if (nums[a].empty())
                firstv[a] = i;

            nums[a].push_back(i);

            IT[i+LEAFOFFSET] = a;
        }

        present.clear();
        for (i=1;i<=n;i++)
        {
            if (!nums[i].empty())
            {
                present.push_back(i);
            }
        }

        for (i=LEAFOFFSET;i>=1;i--)
        {
            IT[i] = MIN(IT[2*i], IT[2*i+1]);
        }

        int rp = 1;
        while(rp < present.size() && !dangerous(present[rp]))
            rp++;

        int ans = (int)present.size() - rp;

        for (i=0;i<present.size();i++)
        {
            if (rp <= i)
                rp = i + 1;

            for (j=0;j<nums[ present[i] ].size();j++)
            {
                setVal(nums[ present[i] ][j], INF);
            }

            while(rp < present.size() && !dangerous(present[rp]))
                rp++;

            int cans = (int)present.size() - rp + i + 1;

            if (cans < ans)
                ans = cans;
        }

        printf("%d\n",ans);
    }

    return 0;
}