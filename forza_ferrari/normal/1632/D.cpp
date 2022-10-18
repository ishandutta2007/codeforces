#include<iostream>
#include<cstdio>
using namespace std;
int n,g[21][200001],lst,ans;
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>g[0][i];
    for(int i=1;i<=20;++i)
        for(int j=1<<i;j<=n;++j)
            g[i][j]=gcd(g[i-1][j],g[i-1][j-(1<<(i-1))]);
    for(int i=1;i<=n;++i)
    {
        int pos=i,qwq=i,val=g[0][i];
        while(1)
        {
            for(int j=20;~j;--j)
                if(pos-(1<<j)>=lst&&gcd(val,g[j][pos])==val)
                    pos-=(1<<j);
            if(val>=i-qwq+1&&val<=i-pos)
            {
                ++ans;
                lst=i;
                break;
            }
            qwq=pos;
            if(pos==lst)
                break;
            val=gcd(val,g[0][pos]);
        }
        cout<<ans<<" ";
    }
    cout<<'\n';
    return 0;
}