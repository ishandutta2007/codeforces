#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int rows[1001],cols[1001];
Int table[1001][1001];

int main()
{
    Int n,m,k;
    Int i,j;
    char ch;
    Int x,y;
    Int d;
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            rows[i]=i;
            cols[j]=j;
            
            scanf("%I64d",&table[i][j]);
        }
    }
    
    for (i=1;i<=k;i++)
    {
        ch=' ';
        while(ch==' ' || ch==10)
        scanf("%c",&ch);
        
        scanf("%I64d %I64d",&x,&y);
        
        ///cout<<ch<<" "<<x<<" "<<y<<" ."<<endl;
        
        if (ch=='c')
        {
            d=cols[x];
            cols[x]=cols[y];
            cols[y]=d;
        }
        else if (ch=='r')
        {
            d=rows[x];
            rows[x]=rows[y];
            rows[y]=d;
        }
        else
        {
            printf("%I64d\n",table[rows[x]][cols[y]]);
        }
    }
    return 0;
}