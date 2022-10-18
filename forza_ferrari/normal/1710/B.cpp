#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,m,cnt,node[200001],x[200001],p[200001],w[200005],sum[200005],val[200005],lg[200001],st[3][21][200001];
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
inline int query(int id,int l,int r)
{
    if(l>r)
        return 0;
    int len=lg[r-l+1];
    return max(st[id][len][l],st[id][len][r-(1<<len)+1]);
}
signed main()
{
    t=read();
    lg[0]=-1;
    for(int i=1;i<=200000;++i)
        lg[i]=lg[i>>1]+1;
    while(t--)
    {
        n=read(),m=read();
        sum[0]=val[0]=w[0]=0;
        for(int i=1;i<=n;++i)
        {
            node[i]=x[i]=read(),p[i]=read();
            for(int j=0;j<=20;++j)
                st[0][j][i]=st[1][j][i]=st[2][j][i]=0;
            sum[i]=val[i]=0;
        }
        sum[n+1]=val[n+1]=w[n+1]=0;
        sort(node+1,node+n+1);
        cnt=unique(node+1,node+n+1)-node-1;
        for(int i=1;i<=n;++i)
        {
            int tmp=lower_bound(node+1,node+cnt+1,x[i])-node;
            int pos=lower_bound(node+1,node+cnt+1,x[i]-p[i])-node;
            ++sum[pos+1];
            --sum[tmp+1];
            val[pos]+=p[i]-(x[i]-node[pos]);
            pos=upper_bound(node+1,node+cnt+1,x[i]+p[i])-node-1;
            --sum[tmp+1];
            ++sum[pos+1];
            val[pos+1]-=p[i]-(node[pos]-x[i]);
        }
        for(int i=1;i<=cnt;++i)
            sum[i]+=sum[i-1];
        for(int i=1;i<=cnt;++i)
        {
            st[0][0][i]=w[i]=sum[i]*(node[i]-node[i-1])+val[i]+w[i-1];
            st[1][0][i]=w[i]-node[i];
            st[2][0][i]=w[i]+node[i];
        }
        for(int len=2;len<=cnt;len<<=1)
            for(int i=1,j=len;j<=cnt;++i,++j)
            {
                st[0][lg[len]][i]=max(st[0][lg[len]-1][i],st[0][lg[len]-1][i+(len>>1)]);
                st[1][lg[len]][i]=max(st[1][lg[len]-1][i],st[1][lg[len]-1][i+(len>>1)]);
                st[2][lg[len]][i]=max(st[2][lg[len]-1][i],st[2][lg[len]-1][i+(len>>1)]);
            }
        for(int i=1;i<=n;++i)
        {
            int pos=lower_bound(node+1,node+cnt+1,x[i])-node,l=lower_bound(node+1,node+cnt+1,x[i]-p[i])-node,r=upper_bound(node+1,node+cnt+1,x[i]+p[i])-node-1;
            int val=max({query(0,1,l-1),query(0,r+1,cnt),query(1,l,pos)+x[i]-p[i],query(2,pos+1,r)-x[i]-p[i]});
            cout<<(val<=m? 1:0);
        }
        cout<<'\n';
    }
    return 0;
}