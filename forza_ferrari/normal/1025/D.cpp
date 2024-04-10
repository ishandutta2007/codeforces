#include<iostream>
#include<cstdio>
#include<stack>
#include<bitset>
using namespace std;
int n,w[701];
bitset<701> a[705];
bitset<701> sum[705][2];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        w[i]=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(gcd(w[i],w[j])^1)
                a[i][j]=a[j][i]=1;
    for(int i=1;i<=n;++i)
    	sum[i][0][i]=sum[i][1][i]=1;
    for(int len=1;len<=n;++len)
        for(int i=1,j=len;j<=n;++i,++j)
        {
            bitset<701> dp=sum[i][0]&sum[j][1];
            sum[j][1][i-1]=(dp&a[i-1]).any();
            sum[i][0][j+1]=(dp&a[j+1]).any();
        	if(i==1&&j==n)
        		puts(dp.any()? "Yes":"No");
        }
    return 0;
}