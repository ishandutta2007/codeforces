#include<iostream>
#include<cstring>
#include<cstdio>
#define MD 18
#define MN 200000
#define N 262144
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
	void GetH(char*s,int*sa,int*rk,int n)
	{
		for(int i=1,k=0;i<=n;f[0][rk[i++]-1]=k,k=max(k-1,0)) if(rk[i]>1)
			for(int j=sa[rk[i]-1];s[i+k]==s[j+k];++k);
	}
	void CalSa(int*sa,int*rk,int*SA,int*RK,int n)
	{
		for(int i=1;i<=n;++i) v[rk[sa[i]]]=i;
		for(int i=n;i;--i) if(sa[i]>k) SA[v[rk[sa[i]-k]]--]=sa[i]-k;
		for(int i=n-k+1;i<=n;++i) SA[v[rk[i]]--]=i;
		for(int i=1;i<=n;++i) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+k]!=rk[SA[i-1]+k]);
	}
	void Build(char*s,int n)
	{
		memset(f,63,sizeof(f));Lg[0]=-1;
		for(int i=1;i<=n;++i) ++v[s[i]-'a'];
		for(int i=1;i<26;++i) v[i]+=v[i-1];
		for(int i=1;i<=n;++i) sa[q][v[s[i]-'a']--]=i;
		for(int i=1;i<=n;++i) rk[q][sa[q][i]]=rk[q][sa[q][i-1]]+(s[sa[q][i]]!=s[sa[q][i-1]]);
		for(k=1;k<n;k<<=1,swap(p,q)) CalSa(sa[q],rk[q],sa[p],rk[p],n);
		GetH(s,sa[q],rk[q],n);Sa=sa[q];Rk=rk[q];
		for(int i=1;i<=n;++i) Lg[i]=Lg[i>>1]+1;
		for(int i=1;i<=MD;++i)for(int j=1;j<=n;++j)
			if(j+(1<<i)<=n) f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
	//	for(int i=1;i<=n;++i) printf("%d %d %d\n",i,Sa[i],f[0][i]);
	}
	int Query(int l,int r)
	{
		int lg=Lg[r-l+1];
		return min(f[lg][l],f[lg][r-(1<<lg)+1]);	
	}
	pair<int,int> Inter(int x,int len,int n)
	{
		//cout<<"Inter"
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
char st[MN+5];pair<int,int> t[N*2+5];
int n,ans=0,T[N*2+5];

pair<int,int> QueryMx(int x)
{
	pair<int,int> res(0,0);
	for(x+=N;x;x>>=1) res=min(res,t[x]);
	return res;	
}
void Modify(int x,int v){for(T[x+=N]=v;x>>=1;)T[x]=min(T[x<<1],T[x<<1|1]);}
int Query(int l,int r)
{
	int mn=1e9; 
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) mn=min(mn,T[l+1]);
		if( r&1) mn=min(mn,T[r-1]); 
	}
	return mn;
}
void ModifyMx(int l,int r,pair<int,int> v)
{
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)	
	{
		if(~l&1) t[l+1]=min(t[l+1],v);
		if( r&1) t[r-1]=min(t[r-1],v);	
	}
}
int main()
{
	n=read();scanf("%s",st+1);SA::Build(st,n);
	memset(T,63,sizeof(T));
	for(int i=n;i;--i)
	{
		int j=SA::Rk[i],mx=1,L=1;
		pair<int,int> Mx=QueryMx(j);
		if(Mx.first=-Mx.first) 
		{
			pair<int,int> pos=SA::Inter(j,Mx.second,n);
			mx=Mx.first+1;L=Mx.second+Query(pos.first,pos.second)-i;
		}
		Modify(j,i);pair<int,int> pos=SA::Inter(j,L,n);
		ModifyMx(pos.first,pos.second,make_pair(-mx,L));
	//	cout<<i<<" "<<mx<<" "<<L<<" "<<pos.first<<" "<<pos.second<<endl;
		ans=max(ans,mx);
	}
	printf("%d\n",ans);
	return 0;
}