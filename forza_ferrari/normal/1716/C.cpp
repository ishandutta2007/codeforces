#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[2][200001],pos1[2][200001],pos2[2][200001],ans;
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
        n=read();
        ans=0;
        for(int i=1;i<=n;++i)
        {
            a[0][i]=read()+1;
            pos1[0][i]=pos2[0][i]=0;
        }
        for(int i=1;i<=n;++i)
        {
            a[1][i]=read()+1;
            pos1[1][i]=pos2[1][i]=0;
        }
        if(n==1)
        {
            cout<<max(1,a[1][1])<<'\n';
            continue;
        }
        int maxn=a[0][n]-n;
        pos1[0][n]=n;
        for(int i=n-1;i>=1;--i)
            if(a[0][i]-i>maxn)
            {
                maxn=a[0][i]-i;
                pos1[0][i]=i;
            }
            else
                pos1[0][i]=pos1[0][i+1];
        maxn=a[0][n]+n;
        pos2[0][n]=n;
        for(int i=n-1;i>=1;--i)
            if(a[0][i]+i>maxn)
            {
                maxn=a[0][i]+i;
                pos2[0][i]=i;
            }
            else
                pos2[0][i]=pos2[0][i+1];
        maxn=a[1][n]-n;
        pos1[1][n]=n;
        for(int i=n-1;i>=1;--i)
            if(a[1][i]-i>maxn)
            {
                maxn=a[1][i]-i;
                pos1[1][i]=i;
            }
            else
                pos1[1][i]=pos1[1][i+1];
        maxn=a[1][n]+n;
        pos2[1][n]=n;
        for(int i=n-1;i>=1;--i)
            if(a[1][i]+i>maxn)
            {
                maxn=a[1][i]+i;
                pos2[1][i]=i;
            }
            else
                pos2[1][i]=pos2[1][i+1];
        int tmp=(a[1][1]==1? -1:0);
        ans+=n-1+max(a[0][pos1[0][2]]-(pos1[0][2]-1)-ans,0);
        ans+=n+max(a[1][pos2[1][1]]-(n-pos2[1][1]+1)-ans,0);
        for(int i=1;i<=n;++i)
            if(i&1)
            {
                if(i==1&&tmp==-1)
                    tmp=1;
                else
                {
                    ++tmp;
                    if(a[0][i]>tmp)
                        tmp=a[0][i];
                    ++tmp;
                    if(a[1][i]>tmp)
                        tmp=a[1][i];
                }
                if(i==n)
                    ans=min(ans,tmp);
                else
                {
                    int sum=tmp;
                    sum+=n-i+max(a[1][pos1[1][i+1]]-(pos1[1][i+1]-i)-sum,0);
                    sum+=n-i+max(a[0][pos2[0][i+1]]-(n-pos2[0][i+1]+1)-sum,0);
                    ans=min(ans,sum);
                }
            }
            else
            {
                ++tmp;
                if(a[1][i]>tmp)
                    tmp=a[1][i];
                ++tmp;
                if(a[0][i]>tmp)
                    tmp=a[0][i];
                if(i==n)
                    ans=min(ans,tmp);
                else
                {
                    int sum=tmp;
                    sum+=n-i+max(a[0][pos1[0][i+1]]-(pos1[0][i+1]-i)-sum,0);
                    sum+=n-i+max(a[1][pos2[1][i+1]]-(n-pos2[1][i+1]+1)-sum,0);
                    ans=min(ans,sum);
                }
            }
        cout<<ans<<'\n';
    }
    return 0;
}