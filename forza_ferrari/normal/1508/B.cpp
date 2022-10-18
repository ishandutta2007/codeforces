#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,m,a[100001],c[71][71],b[100001];
inline int calc(int x)
{
    long long res=0;
    for(int i=0;i<=x;i+=2)
        res+=c[x][i];
    return res;
}
signed main()
{
    cin>>t;
    c[0][0]=1;
    for(int i=1;i<64;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    while(t--)
    {
        cin>>n>>m;
        if(n<=63&&calc(n)<m)
        {
            puts("-1");
            continue;
        }
        bool tag=0;
        for(int i=1;i<=n;++i)
        {
            if(!tag)
            {
                if(n-i<64&&calc(n-i)<m)
                {
                    m-=calc(n-i);
                    tag^=1;
                    a[i]=1;
                }
                else
                    a[i]=0;
            }
            else
                if(n-i<64&&calc(n-i)>=m)
                {
                    tag^=1;
                    a[i]=1;
                }
                else
                {
                    m-=calc(n-i);
                    a[i]=0;
                }
        }
        for(int i=1;i<=n;++i)
            b[i]=i;
        int pos=0;
        for(int i=1;i<=n;++i)
            if(a[i])
                if(!pos)
                    pos=i;
                else
                {
                    reverse(b+pos,b+i+1);
                    pos=0;
                }
        for(int i=1;i<=n;++i)
            cout<<b[i]<<" ";
        cout<<'\n';
    }
    return 0;
}