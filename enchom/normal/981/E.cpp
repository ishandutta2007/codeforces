#include <iostream>
#include <stdio.h>
#include <bitset>
#include <vector>
using namespace std;

vector< pair<int,int> > backAdd[10111];
vector< pair<int,int> > frontAdd[10111];
int n,q;

bitset<10001> bs[25];
bitset<10001> ans;

void solve(int L,int R,int dep)
{
    int i,j;

    if (L == R)
    {
        for (i=0;i<frontAdd[L].size();i++)
        {
            if (frontAdd[L][i].first >= L)
            {
                bs[dep] = bs[dep] | (bs[dep]<<frontAdd[L][i].second);
            }
        }

        for (i=0;i<backAdd[L].size();i++)
        {
            if (backAdd[L][i].first < L)
            {
                bs[dep] = bs[dep] | (bs[dep]<<backAdd[L][i].second);
            }
        }

        ans = ans | bs[dep];
        return;
    }

    int mid = (L+R)/2;

    bs[dep+1] = bs[dep];

    for (i=mid+1;i<=R;i++)
    {
        for (j=0;j<backAdd[i].size();j++)
        {
            if (backAdd[i][j].first < L)
            {
                bs[dep+1] = bs[dep+1] | (bs[dep+1]<<backAdd[i][j].second);
            }
        }
    }

    solve(L,mid,dep+1);

    bs[dep+1] = bs[dep];

    for (i=L;i<=mid;i++)
    {
        for (j=0;j<frontAdd[i].size();j++)
        {
            if (frontAdd[i][j].first > R)
            {
                bs[dep+1] = bs[dep+1] | (bs[dep+1]<<frontAdd[i][j].second);
            }
        }
    }

    solve(mid+1,R,dep+1);

    return;
}

vector<int> ansv;

int main()
{
    //freopen("test.txt","r",stdin);

    int i,j;
    int l,r,x;

    scanf("%d %d",&n,&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d %d %d",&l,&r,&x);

        backAdd[r].push_back(make_pair(l,x));
        frontAdd[l].push_back(make_pair(r,x));
    }

    bs[0].set(0);
    solve(1,n,0);

    for (i=1;i<=n;i++)
    {
        if (ans[i] == 1)
        {
            ansv.push_back(i);
        }
    }

    printf("%d\n",(int)ansv.size());

    for (i=0;i<ansv.size();i++)
    {
        if (i!=0)
            printf(" ");
        printf("%d",ansv[i]);
    }

    return 0;
}