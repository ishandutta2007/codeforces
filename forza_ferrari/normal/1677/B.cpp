#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,m;
vector<int> v[1000005],sum[2][1000005];
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
        sum[0][0].resize(m+1);
        sum[1][0].resize(m+1);
        v[0].resize(m+1);
        for(int i=1;i<=n;++i)
        {
            sum[0][i].resize(m+1);
            sum[1][i].resize(m+1);
            sum[0][i][0]=sum[1][i][0]=0;
            v[i].resize(m+1);
            for(int j=1;j<=m;++j)
            {
                sum[0][i][j]=sum[1][i][j]=0;
                char c=getchar();
                while(c<'0'||c>'1')
                    c=getchar();
                v[i][j]=c^48;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                cnt+=v[i][j];
                if(i>1)
                    cnt-=v[i-1][j];
                if(cnt)
                    ++sum[1][i][j];
            }
        cnt=0;
        for(int i=1;i<=m;++i,cnt=0)
            for(int j=1;j<=n;++j)
            {
                cnt+=v[j][i];
                if(cnt)
                {
                    ++sum[0][j][i];
                    if(i!=1&&j<n)
                    {
                        ++sum[0][j+1][1];
                        --sum[0][j+1][i];
                    }
                }
            }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                sum[0][i][j]+=sum[0][i][j-1];
                sum[1][i][j]+=sum[1][i-1][j];
                cout<<sum[0][i][j]+sum[1][i][j]<<" ";
            }
        cout<<'\n';
    }
    return 0;
}