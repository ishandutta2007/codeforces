#include <iostream>
#include <stdio.h>
using namespace std;

int n,q;
int p[300011];
int l[300011];
int freereach[300011];

int IT[1200001];
int LEAFOFFSET=1;

pair<int,int> payedge[300011][21];

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int GetLastReach(int reach)
{
    int l=1,r=n;
    int mid,best;

    while(l<=r)
    {
        mid=(l+r)/2;

        if (p[mid]<=reach)
        {
            best=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    return best;
}

int Rec(int ver,int L,int R,int l,int r)
{
    if (L>r || R<l)
    return 0;
    else if (L>=l && R<=r)
    {
        return IT[ver];
    }
    else
    {
        return MAX( Rec(2*ver,L,(L+R)/2,l,r),Rec(2*ver+1,(L+R)/2+1,R,l,r) );
    }
}

int Query(int L,int R)
{
    return Rec(1,1,LEAFOFFSET+1,L,R);
}

void Update(int ind,int val)
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
    //freopen("sample.txt","r",stdin);
    int i,j;
    int reach=-1;
    int x,y;
    int last_r;
    int themaxit;
    int cost=0;

    scanf("%d",&n);

    while(LEAFOFFSET<n)
    LEAFOFFSET*=2;
    LEAFOFFSET--;

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i],&l[i]);
    }
    p[n+1]=2000000001;
    l[n+1]=1;

    freereach[n]=p[n]+l[n];
    for (i=n-1;i>=1;i--)
    {
        reach=p[i]+l[i];

        last_r=GetLastReach(reach);

        freereach[i]=MAX(reach,Query(i+1,last_r));

        Update(i,freereach[i]);
    }

    for (i=1;i<=n;i++)
    {
        last_r=GetLastReach(freereach[i]);
        last_r++;

        if (last_r>n)
        payedge[i][0]=make_pair(n+1,0);
        else
        payedge[i][0]=make_pair(last_r,p[last_r]-freereach[i]);
    }

    themaxit=0;

    for (i=1;i<=20;i++)
    {
        if ( (1<<i)>n )
        break;

        themaxit=i;

        for (j=1;j<=n;j++)
        {
            if (payedge[j][i-1].first==n+1)
            {
                payedge[j][i]=payedge[j][i-1];
            }
            else
            {
                payedge[j][i].first=payedge[ payedge[j][i-1].first ][i-1].first;
                payedge[j][i].second=payedge[j][i-1].second+payedge[ payedge[j][i-1].first ][i-1].second;
            }
        }
    }

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d %d",&x,&y);

        if (freereach[x]>=p[y])
        {
            printf("0\n");
            continue;
        }

        cost=0;

        for (j=themaxit;j>=0;j--)
        {
            if (payedge[x][j].first<=y)
            {
                cost+=payedge[x][j].second;

                x=payedge[x][j].first;
            }

            if (freereach[x]>=p[y])
            break;
        }

        printf("%d\n",cost);
    }

    return 0;
}