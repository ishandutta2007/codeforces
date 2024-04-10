#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int table[101][10001];
Int GetLeftHere[101][10001];
Int GetRightHere[101][10001];
Int GetOneHere[101][10001];
bool computedright[101][10001];
bool computedleft[101][10001];
Int n,m;

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

Int FixUp(Int k)
{
    if (k>m)
    return k-m;
    else
    return k;
}
Int FixDown(Int k)
{
    if (k<1)
    return k+m;
    else
    return k;
}

Int ComputeGetRightHere(Int x,Int y)
{
    ///cout<<"inside right with "<<x<<","<<y<<endl;
    if (computedright[x][y])
    return GetRightHere[x][y];
    
    if (table[x][y]==1)
    {
        ///cout<<"for "<<x<<","<<y<<" returning 0"<<endl;
        computedright[x][y]=true;
        GetRightHere[x][y]=0;
        return 0;
    }
    else
    {
        Int calc=ComputeGetRightHere(x,FixUp(y+1))+1;
        computedright[x][y]=true;
        ///cout<<"for "<<x<<","<<y<<" returning "<<calc<<endl;
        GetRightHere[x][y]=calc;
        return calc;
    }
}

Int ComputeGetLeftHere(Int x,Int y)
{
    if (computedleft[x][y])
    return GetLeftHere[x][y];
    
    if (table[x][y]==1)
    {
        computedleft[x][y]=true;
        ///cout<<"computed "<<x<<","<<y<<" to "<<0<<endl;
        GetLeftHere[x][y]=0;
        return 0;
    }
    else
    {
        Int calc=ComputeGetLeftHere(x,FixDown(y-1))+1;
        computedleft[x][y]=true;
        ///cout<<"computed "<<x<<","<<y<<" to "<<calc<<endl;
        GetLeftHere[x][y]=calc;
        return calc;
    }
}

int main()
{
    Int i,j;
    Int wrong=false;
    Int sum;
    Int minnsum=999999999;
    bool ones;
    char ch;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        ones=false;
        for (j=1;j<=m;j++)
        {
            computedleft[i][j]=false;
            computedright[i][j]=false;
            scanf("%c",&ch);
            if (ch!='1' && ch!='0')
            {
                j--;
                continue;
            }
            if (ch=='1')
            table[i][j]=1;
            else
            table[i][j]=0;
            
            if (table[i][j]==1)
            ones=true;
        }
        if (!ones)
        {
            wrong=true;
        }
    }
    if (wrong)
    {
        printf("-1\n");
        return 0;
    }
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (!computedleft[i][j])
            {
                GetLeftHere[i][j]=ComputeGetLeftHere(i,j);
            }
            if (!computedright[i][j])
            {
                GetRightHere[i][j]=ComputeGetRightHere(i,j);
            }
            ///cout<<GetLeftHere[i][j]<<" "<<GetRightHere[i][j]<<endl;
            
            GetOneHere[i][j]=MIN(GetRightHere[i][j],GetLeftHere[i][j]);
            
            ///cout<<"GetOneHere["<<i<<"]["<<j<<"]="<<GetOneHere[i][j]<<endl;
        }
    }
    
    for (i=1;i<=m;i++)
    {
        sum=0;
        for (j=1;j<=n;j++)
        {
            sum=sum+GetOneHere[j][i];
        }
        if (sum<minnsum)
        {
            minnsum=sum;
        }
    }
    printf("%I64d\n",minnsum);
    return 0;
}