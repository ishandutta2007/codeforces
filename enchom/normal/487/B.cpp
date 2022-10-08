#include <iostream>
#include <stdio.h>
using namespace std;
#define INF 999999999

int n,s,lim;
int a[100001];

int RMINQ[21][110001];
int RMAXQ[21][110001];
int ROW[100001];

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

void BuildRMQ()
{
    int i,j;

    for (i=1;i<=n;i++)
    {
        RMINQ[0][i]=a[i];
        RMAXQ[0][i]=a[i];
    }

    for (i=1;i<=20;i++)
    {
        for (j=1;j<=n-(1<<i)+1;j++)
        {
            RMINQ[i][j]=MIN( RMINQ[i-1][j],RMINQ[i-1][j+(1<<(i-1))] );
            RMAXQ[i][j]=MAX( RMAXQ[i-1][j],RMAXQ[i-1][j+(1<<(i-1))] );
        }
    }

    ROW[1]=0;

    for (i=2;i<=100000;i++)
    {
        if ( (1<<(ROW[i-1]+1))<=i )
        {
            ROW[i]=ROW[i-1]+1;
        }
        else
        {
            ROW[i]=ROW[i-1];
        }
    }

    return;
}

int F[100001];

int GetMIN(int L,int R)
{
    int sz=R-L+1;
    int row=ROW[sz];

    return MIN(RMINQ[row][L],RMINQ[row][R-(1<<row)+1]);
}

int GetMAX(int L,int R)
{
    int sz=R-L+1;
    int row=ROW[sz];

    return MAX(RMAXQ[row][L],RMAXQ[row][R-(1<<row)+1]);
}

///IT
int IT[600001];
int LEAFOFFSET=1;

void Add(int ind,int val)
{
    ind+=LEAFOFFSET;

    IT[ind]=val;
    ind/=2;

    while(ind>0)
    {
        IT[ind]=MIN(IT[2*ind],IT[2*ind+1]);
        ind/=2;
    }

    return;
}

int Rec(int ver,int L,int R,int l,int r)
{
    if (R<l || L>r)
    return INF;
    else if (L>=l && R<=r)
    {
        return IT[ver];
    }
    else
    {
        return MIN(Rec(2*ver,L,(L+R)/2,l,r),Rec(2*ver+1,(L+R)/2+1,R,l,r));
    }
}

int Query(int L,int R)
{
    if (L==0)
    return MIN(F[0],Rec(1,1,LEAFOFFSET+1,1,R));
    else
    return Rec(1,1,LEAFOFFSET+1,L,R);
}

int main()
{
    //freopen("sample.txt","r",stdin);

    int i;
    int l,r,mid,best;
    int L,R;

    scanf("%d %d %d",&n,&s,&lim);

    while(LEAFOFFSET<n)
    LEAFOFFSET*=2;
    LEAFOFFSET--;

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    BuildRMQ();

    for (i=1;i<=2*LEAFOFFSET+1;i++)
    {
        IT[i]=INF;
    }

    F[0]=0;

    for (i=1;i<=n;i++)
    {
        l=1;
        r=i-lim+1;
        best=-1;

        while(l<=r)
        {
            mid=(l+r)/2;

            if (GetMAX(mid,i)-GetMIN(mid,i)>s)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
                best=mid;
            }
        }

        if (best==-1)
        {
            F[i]=INF;
        }
        else
        {
            L=best-1;
            R=(i-lim+1)-1;

            //cout<<"Calling for "<<L<<"~"<<R<<endl;
            F[i]=Query(L,R)+1;
        }

        //cout<<"F["<<i<<"]="<<F[i]<<endl;

        Add(i,F[i]);
    }

    if (F[n]<INF)
    printf("%d\n",F[n]);
    else
    printf("-1\n");

    return 0;
}