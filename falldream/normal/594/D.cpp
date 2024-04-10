#include<iostream>
#include<cstdio>
#include<vector>
#define mod 1000000007
#define MN 1000000
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
vector<pair<int,int> >v[MN+5];
int s[MN/5],num=0,last[MN+5],vis[MN+5],la[MN+5],lastans=0,n,q,mx,a[MN+5],rt[MN+5],cnt=0,inv[MN+5],Ans[MN+5];
struct Tree{int l,r,x;}T[MN*4+5];bool b[MN+5];
int Build(int l,int r)
{
    int x=++cnt;T[x].x=1;
    if(l!=r)
    {
        int mid=l+r>>1;
        T[x].l=Build(l,mid);T[x].r=Build(mid+1,r);
    }
    return x;
}
void Modify(int x,int l,int r,int lt,int rt,int v)
{
    if(l==lt&&r==rt){T[x].x=1LL*T[x].x*v%mod;return;}
    int mid=lt+rt>>1;
    if(r<=mid) Modify(T[x].l,l,r,lt,mid,v);
    else if(l>mid) Modify(T[x].r,l,r,mid+1,rt,v);
    else Modify(T[x].l,l,mid,lt,mid,v),
         Modify(T[x].r,mid+1,r,mid+1,rt,v);
}
void Query(int x,int k,int lt,int rt)
{
    lastans=1LL*lastans*T[x].x%mod;
    if(lt==rt) return;int mid=lt+rt>>1;
    if(k<=mid) Query(T[x].l,k,lt,mid);
    else Query(T[x].r,k,mid+1,rt);
}
int main()
{
    n=read();inv[0]=inv[1]=1;
    for(int i=1;i<=n;++i) mx=max(mx,a[i]=read());
	q=read();
    for(register int i=2;i<=mx;++i)
    {
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
        if(!b[i]) s[++num]=i,last[i]=i;
        for(int j=1;s[j]*i<=mx;++j)
        {
            b[s[j]*i]=1;last[s[j]*i]=s[j];
            if(i%s[j]==0) break;
        }
    }
    rt[0]=Build(1,n);
    for(int i=1;i<=q;++i) 
    {
    	int l=read(),r=read();
		v[r].push_back(make_pair(l,i));	
    }
    for(register int i=1;i<=n;++i)
    {
        Modify(rt[i]=rt[i-1],1,i,1,n,a[i]);
        for(int t=a[i];t>1;t/=last[t])
            if(vis[last[t]]!=i)
            {
                vis[last[t]]=i;
                Modify(rt[i],la[last[t]]+1,i,1,n,1LL*inv[last[t]]*(last[t]-1)%mod);
                la[last[t]]=i;
            }
        for(int j=0;j<v[i].size();++j) 
			lastans=1,Query(rt[i],v[i][j].first,1,n),Ans[v[i][j].second]=lastans;
    }
    for(int i=1;i<=q;++i) printf("%d\n",Ans[i]);
    return 0;
}