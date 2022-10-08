#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n,m;
int paint[100111];
int cnt[100111];

int IT[500111];
int LEAFOFFSET=1;

int Left[100111];
int Right[100111];

int MAX(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}

int getMax(int ind)
{
    ind+=LEAFOFFSET;

    int ans=IT[ind];

    while(ind>1)
    {
        if (ind%2==1)
            ans=MAX(ans,IT[ind-1]);

        ind/=2;
    }

    return ans;
}

void Upd(int ind,int val)
{
    ind+=LEAFOFFSET;

    IT[ind]=val;
    ind/=2;

    while(ind>0)
    {
        IT[ind]=MAX(IT[2*ind],IT[2*ind+1]);
        ind/=2;
    }

    return;
}

int main()
{
    int i,j;
    int l,r;
    int ctr=0;
    int ans,maxans=0;

    scanf("%d %d",&n,&m);

    LEAFOFFSET=1;
    while(LEAFOFFSET<(n+1))
        LEAFOFFSET*=2;
    LEAFOFFSET--;

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&l,&r);

        paint[l]++;
        paint[r+1]--;
    }

    for (i=1;i<=m;i++)
    {
        ctr+=paint[i];

        cnt[i]=ctr+1;
    }

    ///Left-to-right
    for (i=1;i<=m;i++)
    {
        Left[i] = getMax(cnt[i])+1;

        Upd(cnt[i],Left[i]);
    }

    ///Right-to-left
    memset(IT,0,sizeof(IT));

    for (i=m;i>=1;i--)
    {
        Right[i] = getMax(cnt[i])+1;

        Upd(cnt[i],Right[i]);
    }

    ///Solution
    for (i=1;i<=m;i++)
    {
        ans=Left[i]+Right[i]-1;

        if (ans>maxans)
            maxans=ans;
    }

    printf("%d\n",maxans);

    return 0;
}