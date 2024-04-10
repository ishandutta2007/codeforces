#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
typedef long long Int;

int gcd(int a,int b)
{
    int r;

    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int n;
int nums[100001];
int q;
int queries[300001];
vector< pair<int,int> > ans;
int RQ[21][100001];
int BestSize[100001];

map<int,Int> mymap;
map<int,Int>::iterator myit;

int GetGCD(int L,int R)
{
    if (L>R)
    return 0;

    int row=BestSize[R-L+1];

    return gcd( RQ[row][L] , RQ[row][ R-(1<<row)+1 ] );
}

int main()
{
    //freopen("sample.txt","r",stdin);

    int i,j;
    int base;
    int LIM;
    int l,r,mid,best;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d",&queries[i]);
        mymap.insert( make_pair(queries[i],0) );
    }

    for (i=1;i<=n;i++)
    {
        RQ[0][i]=nums[i];
    }

    for (i=1;i<=20;i++)
    {
        for (j=1;j<=n-(1<<i)+1;j++)
        {
            RQ[i][j]=gcd(RQ[i-1][j],RQ[i-1][ j+(1<<(i-1)) ]);
        }
    }

    BestSize[1]=0;
    for (i=2;i<=100000;i++)
    {
        if ( ( 1<<(BestSize[i-1]+1) )<=i )
        BestSize[i]=BestSize[i-1]+1;
        else
        BestSize[i]=BestSize[i-1];
    }

    ///Solution
    for (i=1;i<=n;i++)
    {
        //cout<<"Working with "<<i<<endl;

        base=GetGCD(i,n);
        LIM=n;

        while(LIM>=i)
        {
            //cout<<"Entering with LIM="<<LIM<<" and base="<<base<<endl;
            l=i;
            r=LIM;

            while(l<=r)
            {
                mid=(l+r)/2;

                if (GetGCD(i,mid)==base)
                {
                    best=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }

            //ans.push_back(make_pair( base,LIM-best+1 ));

            myit=mymap.find(base);
            if (myit!=mymap.end())
            {
                (*myit).second=(*myit).second+(Int)(LIM-best+1);
            }

            LIM=best-1;
            base=GetGCD(i,LIM);
        }
    }

    for (i=1;i<=q;i++)
    {
        myit=mymap.find(queries[i]);
        printf("%I64d\n",(*myit).second);
    }

    return 0;
}