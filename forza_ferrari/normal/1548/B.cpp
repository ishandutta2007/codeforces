#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,a[200001],g[21][200001];
inline int gcd(int x,int y)
{
    if(!x||!y)
        return x|y;
    return x%y? gcd(y,x%y):y;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(i^1)
            {
                g[0][i-1]=a[i]-a[i-1];
                if(g[0][i-1]<0)
                    g[0][i-1]=-g[0][i-1];
            }
        }
        for(int i=1;i<=20;++i)
            for(int j=1;j+(1<<i)-1<n;++j)
                g[i][j]=gcd(g[i-1][j],g[i-1][j+(1<<(i-1))]);
        int ans=1;
        for(int i=1;i<n;++i)
        {
            int pos=i,val=g[0][i];
            for(int j=20;~j;--j)
                if(pos+(1<<j)-1<n&&gcd(val,g[j][pos])!=1)
                {
                    val=gcd(val,g[j][pos]);
                    pos+=1<<j;
                }
            ans=max(ans,pos-i+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}