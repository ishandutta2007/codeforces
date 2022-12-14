#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 400
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5][MN+5];
int n,m,mod,a[MN+5][MN+5],s[MN*MN+5],res,cnt,id[MN*MN+5];
inline int getfa(int x){return s[x]?s[x]=getfa(s[x]):x;}
int pow(int x,int k)
{
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod)
		if(k&1) sum=1LL*sum*x%mod;
	return sum;	
}
#define O(x) ((x)&1)
#define num(x,y) ((x)-1)*(m+1)+y
inline void Merge(int x,int y)
{
	if(getfa(x)==getfa(y)) res=0;
	else s[getfa(x)]=getfa(y); 
}
inline void ins(int f,int t)
{
	f=id[getfa(f)];t=id[getfa(t)];
	(++a[f][f])%=mod;(a[f][t]+=mod-1)%=mod;
	(++a[t][t])%=mod;(a[t][f]+=mod-1)%=mod;	
}
int Gauss(int n)
{
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j) if(a[j][i])
		{
			if(j!=i) 
			{
				res=mod-res;
				for(int k=i;k<=n;++k) swap(a[i][k],a[j][k]);	
			}
			break;
		}
		if(!a[i][i]) return 0;
		int inv=pow(a[i][i],mod-2);
		for(int j=i+1;j<=n;++j)
		{
			int Inv=1LL*inv*a[j][i]%mod;
			for(int k=i;k<=n;++k) a[j][k]=(a[j][k]-1LL*a[i][k]*Inv%mod+mod)%mod;	
		}
	}
	for(int i=1;i<=n;++i) res=1LL*res*a[i][i]%mod;
	return res;
}
int Solve(int o)
{
	memset(s,0,sizeof(s));res=1;
	memset(a,0,sizeof(a));cnt=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(st[i][j]=='\\'&&O(i+j+o)) Merge(num(i,j),num(i+1,j+1));
			if(st[i][j]=='/'&&O(i+j+o+1)) Merge(num(i,j+1),num(i+1,j));
		}
	for(int i=1;i<=n+1;++i) for(int j=1;j<=m+1;++j)
		if(O(i+j+o)&&getfa(num(i,j))==num(i,j)) id[num(i,j)]=++cnt;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) if(st[i][j]=='*')
		{
			if(O(i+j+o)) ins(num(i,j),num(i+1,j+1));
			else ins(num(i,j+1),num(i+1,j)); 
		}
	return Gauss(cnt-1);
}

int main()
{
	n=read();m=read();mod=read();
	for(int i=1;i<=n;++i) scanf("%s",st[i]+1);
	printf("%d\n",(Solve(0)+Solve(1))%mod);
	return 0;
}