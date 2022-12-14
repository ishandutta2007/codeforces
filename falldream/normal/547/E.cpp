#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 400000
#define MD 18
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace SA
{
    int sa[2][MN+5],rk[2][MN+5],k,v[MN+5],p=1,q=0,*Sa,*Rk,f[MD+1][MN+5],Lg[MN+5];
    void GetH(int*s,int*sa,int*rk,int n)
    {
        for(int i=1,k=0;i<=n;f[0][rk[i++]-1]=k,k?--k:0) if(rk[i]>1)
            for(int j=sa[rk[i]-1];s[i+k]==s[j+k];++k);
    }
    void CalSa(int*sa,int*rk,int*SA,int*RK,int n)
    {
        for(int i=1;i<=n;++i) v[rk[sa[i]]]=i;
        for(int i=n;i;--i) if(sa[i]>k) SA[v[rk[sa[i]-k]]--]=sa[i]-k;
        for(int i=n-k+1;i<=n;++i) SA[v[rk[i]]--]=i;
        for(int i=1;i<=n;++i) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+k]!=rk[SA[i-1]+k]);
    }
    void Build(int*s,int n)
    {
        memset(f,63,sizeof(f));Lg[0]=-1;
        for(int i=1;i<=n;++i) ++v[s[i]];
        for(int i=1;i<=MN;++i) v[i]+=v[i-1];
        for(int i=1;i<=n;++i) sa[q][v[s[i]]--]=i;
        for(int i=1;i<=n;++i) rk[q][sa[q][i]]=rk[q][sa[q][i-1]]+(s[sa[q][i]]!=s[sa[q][i-1]]);
        for(k=1;k<n;k<<=1,swap(p,q)) CalSa(sa[q],rk[q],sa[p],rk[p],n);
        GetH(s,sa[q],rk[q],n);Sa=sa[q];Rk=rk[q];
        for(int i=1;i<=n;++i) Lg[i]=Lg[i>>1]+1;
        for(int i=1;i<=MD;++i)for(int j=1;j<=n;++j)
            if(j+(1<<i)<=n) f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
    }
    int Query(int l,int r)
    {
        int lg=Lg[r-l+1];
        return min(f[lg][l],f[lg][r-(1<<lg)+1]);    
    }
    pair<int,int> Inter(int x,int len,int n)
    {
        int l=1,r=x-1,mid,L=x,R=x;
        while(l<=r)
            if(Query(mid=(l+r>>1),x-1)>=len) L=mid,r=mid-1;
            else l=mid+1;
        l=x+1,r=n;
        while(l<=r)
            if(Query(x,(mid=(l+r>>1))-1)>=len) R=mid,l=mid+1;
            else r=mid-1;
        return make_pair(L,R);
    }
}
char s[MN+5];
int n,Q,pos[MN+5],L=0,cnt=0,a[MN+5],rt[MN+5];
struct Tree{int l,r,x;}T[MN*20+5];
void Modify(int x,int nx,int l,int r,int k)
{
	T[nx].x=T[x].x+1;
	if(l==r) return;int mid=l+r>>1;
	if(k<=mid) T[nx].r=T[x].r,Modify(T[x].l,T[nx].l=++cnt,l,mid,k);
	else T[nx].l=T[x].l,Modify(T[x].r,T[nx].r=++cnt,mid+1,r,k);
}
int Query(int x,int l,int r,int L,int R)
{
	if(!x) return 0;
	if(l==L&&r==R) return T[x].x;
	int mid=l+r>>1;
	if(R<=mid) return Query(T[x].l,l,mid,L,R);
	else if(L>mid) return Query(T[x].r,mid+1,r,L,R);
	else return Query(T[x].l,l,mid,L,mid)+Query(T[x].r,mid+1,r,mid+1,R); 
}
int main()
{
	n=read();Q=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);int len=strlen(s+1);
		if(i>1) a[++L]=25+i;pos[i]=L+1;
		for(int j=1;j<=len;++j) a[++L]=s[j]-'a'+1;
	}
	pos[n+1]=L+2;SA::Build(a,L);
	for(int i=1;i<=L;++i) Modify(rt[i-1],rt[i]=++cnt,1,L,SA::Rk[i]);
	for(int i=1;i<=Q;++i)
	{
		int l=read(),r=read(),k=read();
		pair<int,int> s=SA::Inter(SA::Rk[pos[k]],pos[k+1]-pos[k]-1,L);
		printf("%d\n",Query(rt[pos[r+1]-2],1,L,s.first,s.second)-Query(rt[pos[l]-1],1,L,s.first,s.second));
	}
	return 0;
}