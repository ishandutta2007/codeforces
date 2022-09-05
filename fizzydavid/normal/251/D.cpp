#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[100111];
bool g[64][100111],res[100111];
int id[64];
void gauss(ll q,bool F)
{
    for(int i=60;i>=0;i--)
    {
        if(((q>>i)&1)!=F)
        {
            for(int j=0;j<n;j++)
                g[m][j]=(a[j]>>i)&1;
            g[m][n]=F;
            for(int j=0;j<m;j++)
            {
                if(g[m][id[j]])
                {
                    for(int k=0;k<=n;k++)
                        g[m][k]^=g[j][k];
                }
            }
            int pos=-1;
            for(int j=0;j<n;j++)
            {
                if(g[m][j])
                {
                    pos=j;
                    break;
                }
            }
            if(pos!=-1)
                id[m++]=pos;
        }
    }
}
int main()
{
    ll q=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        q=q^a[i];
    }
    gauss(q,1);
    gauss(q,0);
    for(int i=m-1;i>=0;i--)
    {
        res[id[i]]=g[i][n];
        for(int j=0;j<n;j++)
            if(j!=id[i]&&g[i][j])
                res[id[i]]^=res[j];
    }
    for(int i=0;i<n;i++)
    {
        if(res[i])
            putchar('1');
        else
            putchar('2');
        putchar(' ');
    }
    putchar('\n');
    return 0;
}