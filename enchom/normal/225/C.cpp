#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char table[1001][1001];
Int tobeblack[1001];
Int tobewhite[1001];
Int toendblack[1001];
Int toendwhite[1001];
Int F[1001][2][1001];
Int n,m;
Int x,y;

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

Int SumBlack(Int a,Int b)
{
    return toendblack[b]-toendblack[a-1];
}
Int SumWhite(Int a,Int b)
{
    return toendwhite[b]-toendwhite[a-1];
}

Int Batrak(Int k,Int color,Int length)
{
    ///cout<<"inside with "<<k<<" "<<color<<" "<<length<<endl;
    if (F[k][color][length]!=-1)
    {
        ///cout<<"alredy precomputed "<<F[k][color][length]<<endl<<endl;
        return F[k][color][length];
    }
    else
    {
        Int ans;
        Int opc;
        Int num1,num2;
        if (color==1)
        opc=0;
        else
        opc=1;
        
        if (length<y)
        {
            num1=Batrak(k-1,color,length+1);
            if (color==1)
            num1+=tobeblack[k];
            else
            {
                ///cout<<"adding tobewhite "<<k<<" "<<color<<" "<<length<<" ";
                num1+=tobewhite[k];
                ///cout<<" now its "<<num2<<endl;
            }
        }
        else
        {
            num1=999999999999;
        }
        
        if (k<x)
        {
            num2=999999999999;
        }
        else
        {
            num2=Batrak(k-x,opc,x);
            if (opc==1)
            num2+=SumBlack(k-x+1,k);
            else
            num2+=SumWhite(k-x+1,k);
        }
        
        ans=MIN(num1,num2);
        ///cout<<"got ans for "<<k<<" "<<color<<" "<<length<<" --- "<<ans<<" --- "<<num1<<" / "<<num2<<endl<<endl;
        
        F[k][color][length]=ans;
        return ans;
    }
}

int main()
{
    Int i,j,in;
    Int ans;
    
    scanf("%I64d %I64d %I64d %I64d",&n,&m,&x,&y);
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            scanf("%c",&table[i][j]);
            if (table[i][j]!='.' && table[i][j]!='#')
            j--;
        }
    }
    
    for (i=1;i<=m;i++)
    {
        tobeblack[i]=0;
        tobewhite[i]=0;
        for (j=1;j<=n;j++)
        {
            if (table[j][i]=='#')
            tobewhite[i]++;
            else
            tobeblack[i]++;
        }
    }
    for (i=1;i<=1000;i++)
    {
        for (in=1;in<=1000;in++)
        {
            F[i][0][in]=-1;
            F[i][1][in]=-1;
        }
        F[0][0][i]=0;
        F[0][1][i]=0;
    }
    
    toendblack[0]=0;
    toendwhite[0]=0;
    for (i=1;i<=m;i++)
    {
        toendblack[i]=toendblack[i-1]+tobeblack[i];
        toendwhite[i]=toendwhite[i-1]+tobewhite[i];
    }
    ans=MIN(Batrak(m-x,0,x)+SumWhite(m-x+1,m),Batrak(m-x,1,x)+SumBlack(m-x+1,m));
    
    printf("%I64d\n",ans);
    return 0;
}