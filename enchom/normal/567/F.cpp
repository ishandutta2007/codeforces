#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
typedef long long Int;

vector<int> Larger[101];
vector<int> LargerOrEqual[101];
vector<int> Equal[101];
int n,k;

Int F[101][101];
int values[101];

bool Check(int k)
{
    int i;

    for (i=0;i<Equal[k].size();i++)
    {
        if (values[k]!=values[ Equal[k][i] ])
        return false;
    }

    for (i=0;i<LargerOrEqual[k].size();i++)
    {
        if (values[k]<values[ LargerOrEqual[k][i] ])
        return false;
    }

    for (i=0;i<Larger[k].size();i++)
    {
        if (values[k]<=values[ Larger[k][i] ])
        return false;
    }

    return true;
}

Int Solve(int L,int R,int val)
{
    if (F[L][R]!=-1)
    return F[L][R];

    if (R-L+1==2)
    {
        values[L]=val;
        values[R]=val;

        if (Check(L) && Check(R))
        {
            F[L][R]=1;
        }
        else
        {
            F[L][R]=0;
        }

        values[L]=999;
        values[R]=999;

        return F[L][R];
    }

    ///All left
    Int ans=0;

    values[L]=val;
    values[L+1]=val;

    if ( Check(L) && Check(L+1) )
    {
        ans+=Solve(L+2,R,val+1);
    }

    values[L]=999;
    values[L+1]=999;

    //

    values[R]=val;
    values[R-1]=val;

    if ( Check(R) && Check(R-1) )
    {
        ans+=Solve(L,R-2,val+1);
    }

    values[R]=999;
    values[R-1]=999;

    //

    values[L]=val;
    values[R]=val;

    if ( Check(L) && Check(R) )
    {
        ans+=Solve(L+1,R-1,val+1);
    }

    values[L]=999;
    values[R]=999;

    F[L][R]=ans;

    return ans;
}

int main()
{
    int i;
    int a,b;
    char op[4];

    memset(F,-1,sizeof(F));

    scanf("%d %d",&n,&k);

    for (i=1;i<=k;i++)
    {
        scanf("%d",&a);
        scanf("%s",op);
        scanf("%d",&b);

        if (strlen(op)==1)
        {
            if (op[0]=='=')
            {
                Equal[a].push_back(b);
                Equal[b].push_back(a);
            }
            else if (op[0]=='>')
            {
                Larger[a].push_back(b);
            }
            else
            {
                Larger[b].push_back(a);
            }
        }
        else
        {
            if (op[0]=='>')
            {
                LargerOrEqual[a].push_back(b);
            }
            else
            {
                LargerOrEqual[b].push_back(a);
            }
        }
    }

    for (i=1;i<=2*n;i++)
    {
        values[i]=999;
    }
    printf("%lld\n",Solve(1,2*n,1));

    return 0;
}