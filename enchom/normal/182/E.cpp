#include <iostream>
using namespace std;

typedef long long Int;

struct wood
{
    Int wid,len;
};

Int MOD=1000000007;
Int F[201][3001];
Int careful[201];
wood types[201];
Int tL=0;

int main()
{
    Int n,l;
    Int i,j,in,a,b;
    Int ways;
    Int totalways=0;
    
    cin>>n>>l;
    
    for (i=0;i<=200;i++)
    careful[i]=0;
    for (i=1;i<=n;i++)
    {
        cin>>a>>b;
        tL++;
        types[tL].len=a;
        types[tL].wid=b;
        
        if (a!=b)
        {
            careful[tL]=tL+1;
            careful[tL+1]=tL;
            tL++;
            types[tL].len=b;
            types[tL].wid=a;
        }
    }
    for (i=0;i<=200;i++)
    {
        for (j=0;j<=3000;j++)
        F[i][j]=0;
    }
    for (i=1;i<=l;i++)
    {
        for (j=1;j<=tL;j++)
        {
            ways=0;
            if (types[j].len>i)
            continue;
            if (types[j].len==i)
            {
                F[j][i]=1;
                continue;
            }
            
            
            for (in=1;in<=tL;in++)
            {
                if (in==j || careful[j]==in)
                continue;
                
                if (types[in].wid==types[j].len)
                {
                    ways=(ways+F[in][i-types[j].len])%MOD;
                }
            }
            
            F[j][i]=ways;
        }
    }
    for (i=1;i<=tL;i++)
    {
        totalways=(totalways+F[i][l])%MOD;
    }
    cout<<totalways<<endl;
    return 0;
}