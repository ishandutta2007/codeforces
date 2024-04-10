#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,sum[1000001];
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
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=0;i<=m;++i)
            sum[i]=0;
        for(int i=1;i<=n;++i)
            ++sum[read()];
        for(int i=1;i<=m;++i)
            sum[i]+=sum[i-1];
        bool flag=1;
        for(int i=1;i<=m;++i)
        {
            if(sum[i]-sum[i-1]==0)
                continue;;
            for(int j=i;j<=m;j+=i)
                if(sum[min(m,j+i-1)]-sum[j-1])
                    if(sum[j/i]-sum[j/i-1]==0)
                    {
                        flag=0;
                        break;
                    }
            if(!flag)
                break;
        }
        cout<<(flag? "Yes":"No")<<'\n';
    }
    return 0;
}