#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct vertex
{
    int x,w;
    int id;
};

int n;
vertex vers[300001];
vertex versorder[300001];

int IT[600001];
int LEAFOFFSET=1;

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

void Update(int x,int val)
{
    int ind=x+LEAFOFFSET;

    IT[ind]=val;
    ind/=2;

    while(ind>0)
    {
        IT[ind]=MAX(IT[2*ind],IT[2*ind+1]);
        ind/=2;
    }

    return;
}

int GetR(int x)
{
    int ind=x+LEAFOFFSET;
    int ans=IT[ind];

    while(ind>1)
    {
        if (ind%2==0)
        ans=MAX(ans,IT[ind+1]);

        ind/=2;
    }

    return ans;
}

int BS(int val)
{
    int l=1,r=n,mid,best=-1;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (vers[mid].x-vers[mid].w>=val)
        {
            best=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }

    return best;
}

bool SORT(vertex a,vertex b)
{
    return (a.x-a.w)<(b.x-b.w);
}

bool ORDER(vertex a,vertex b)
{
    return a.x<b.x;
}

int WhereIs[200011];

int main()
{
    int i;
    int bestid,bestval;
    int answer=0;

    scanf("%d",&n);

    LEAFOFFSET=1;
    while(LEAFOFFSET<n)
    LEAFOFFSET*=2;
    LEAFOFFSET--;

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&vers[i].x,&vers[i].w);
        vers[i].id=i;

        versorder[i]=vers[i];
    }

    sort(vers+1,vers+1+n,SORT);
    sort(versorder+1,versorder+1+n,ORDER);

    for (i=1;i<=n;i++)
    {
        WhereIs[ vers[i].id ]=i;
    }

    for (i=n;i>=1;i--)
    {
        bestid=BS(versorder[i].x+versorder[i].w);

        if (bestid==-1)
        bestval=1;
        else
        bestval=1+GetR(bestid);

        Update(WhereIs[ versorder[i].id ],bestval);

        if (bestval>answer)
        answer=bestval;
    }

    printf("%d\n",answer);

    return 0;
}