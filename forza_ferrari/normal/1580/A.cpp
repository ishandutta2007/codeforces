#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,a[401][401],minn,sum[401][401],ans[401];
/*len-sum[j]+len-sun[i]+sum[i][j]*/
/*inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void push_up(int k)
{
    ans[k]=min(ans[ls(k)],ans[rs(k)]);
}
inline void push_down(int k)
{
    if(tag[k])
    {
        ans[ls(k)]+=tag[k];
        ans[rs(k)]+=tag[k];
        tag[ls(k)]+=tag[k];
        tag[rs(k)]+=tag[k];
        tag[k]=0;
    }
}
void clear(int l,int r,int k)
{
    ans[k]=tag[k]=0;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    clear(l,mid,ls(k));
    clear(mid+1,r,rs(k));
}
void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        ans[k]+=p;
        tag[k]+=p;
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
int query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return ans[k];
    push_down(k);
    int mid=(l+r)>>1,res=1<<30;
    if(nl<=mid)
        res=min(res,query(nl,nr,l,mid,ls(k)));
    if(nr>mid)
        res=min(res,query(nl,nr,mid+1,r,rs(k)));
    return res;
}*/
inline int query(int x,int y,int l,int r)
{
    return sum[x][y]-sum[l-1][y]-sum[x][r-1]+sum[l-1][r-1];
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
            {
                char c=getchar();
                while(c<'0'||c>'1')
                    c=getchar();
                a[i][j]=c-'0';
            }
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        minn=n*m;
        for(register int i=1;i<=n;++i)
            for(register int j=i+4;j<=n;++j)
                for(register int k=1;k<=m;++k)
                {
                    if(k>3)
                    {
                        int pos=ans[k-3];
                        minn=min(minn,(j-i-1)-query(j-1,pos,i+1,pos)+(k-pos-1)-query(i,k-1,i,pos+1)+(k-pos-1)-query(j,k-1,j,pos+1)+(j-i-1)-query(j-1,k,i+1,k)+query(j-1,k-1,i+1,pos+1));
                    }
                    ans[k]=k;
                    if(k==1)
                        continue;
                    int pos=ans[k-1];
                    if((j-i-1)-query(j-1,pos,i+1,pos)+(k-pos)-query(i,k,i,pos+1)+(k-pos)-query(j,k,j,pos+1)+query(j-1,k,i+1,pos+1)<(j-i-1)-query(j-1,k,i+1,k))
                        ans[k]=pos;
                }
        printf("%d\n",minn);
    }
    return 0;
}