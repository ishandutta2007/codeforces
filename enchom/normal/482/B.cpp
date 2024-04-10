#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

struct query
{
    int l,r,q;
};

int AllOnes=( (1<<30)-1 )*2+1;
int n,m;
vector<int> Add[200001];
vector<int> Remove[200001];
query qs[200001];
int arr[200001];

int IT[1000001];
int LEAFOFFSET=1;
int ctr=0;

int Place[200001];

void RemoveVal(int ind)
{
    ind=LEAFOFFSET+Place[ind];
    IT[ind]=0;
    ind/=2;

    while(ind>0)
    {
        IT[ind]=IT[2*ind]|IT[2*ind+1];
        ind/=2;
    }

    return;
}

int GetTop()
{
    return IT[1];
}

void AddVal(int ind)
{
    int org=ind;

    ctr++;
    Place[ind]=ctr;

    ind=LEAFOFFSET+ctr;
    IT[ind]=qs[org].q;
    ind/=2;

    while(ind>0)
    {
        IT[ind]=IT[2*ind]|IT[2*ind+1];
        ind/=2;
    }

    return;
}

///

int IT2[1000001];

void Add2(int ind,int num)
{
    ind=ind+LEAFOFFSET;
    IT2[ind]=num;
    ind/=2;

    while(ind>0)
    {
        IT2[ind]=IT2[2*ind]&IT2[2*ind+1];
        ind/=2;
    }

    return;
}

int Query_Rec(int ver,int L,int R,int l,int r)
{
    if (L>r || R<l)
    return AllOnes;
    else if (L>=l && R<=r)
    {
        return IT2[ver];
    }
    else
    {
        return Query_Rec(2*ver,L,(L+R)/2,l,r)&Query_Rec(2*ver+1,(L+R)/2+1,R,l,r);
    }
}

int Query(int l,int r)
{
    return Query_Rec(1,1,LEAFOFFSET+1,l,r);
}

///

int main()
{
    int i,j;
    int thenum;

    scanf("%d %d",&n,&m);

    /*
    while(LEAFOFFSET<m)
    LEAFOFFSET*=2;
    LEAFOFFSET--;
    */
    while(LEAFOFFSET<100000)
    LEAFOFFSET*=2;
    LEAFOFFSET--;

    memset(IT,0,sizeof(IT));

    for (i=1;i<=m;i++)
    {
        scanf("%d %d %d",&qs[i].l,&qs[i].r,&qs[i].q);

        Add[ qs[i].l ].push_back(i);
        Remove[ qs[i].r+1 ].push_back(i);
    }

    for (i=1;i<=n;i++)
    {
        for (j=0;j<Remove[i].size();j++)
        {
            RemoveVal(Remove[i][j]);
        }

        for (j=0;j<Add[i].size();j++)
        {
            AddVal(Add[i][j]);
        }

        thenum=GetTop();

        arr[i]=thenum;
    }

    memset(IT2,0,sizeof(IT2));

    for (i=1;i<=n;i++)
    {
        Add2(i,arr[i]);
    }

    for (i=1;i<=m;i++)
    {
        if (Query(qs[i].l,qs[i].r)!=qs[i].q)
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    for (i=1;i<=n;i++)
    {
        printf("%d",arr[i]);
        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}