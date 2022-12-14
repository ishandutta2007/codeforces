#include<bits/stdc++.h>
#define MN 2000
#define MX 720
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int ans=1e9,n,a[MN+5],b[MN+5],cnt,num[MX+5],A[6],c[MX+5][5];
int id[10][10][10][10],f[15000005],q[15000005],top;
void dfs(int x,int v)
{
	++cnt;num[cnt]=x-1;id[A[1]][A[2]][A[3]][A[4]]=cnt;
	for(int j=1;j<x;++j) c[cnt][j]=A[j];
	if(x>4)return;
	for(int i=v;i<=9;++i) A[x]=i,dfs(x+1,i);
	A[x]=0;
}
inline int ID(int x,int y,int z){return x*MX*10+y*10+z;}
void Try(int x,int y,int z,int v)
{
	int d=ID(x,y,z);
	if(v<f[d]) f[q[++top]=d]=v;	
}
int main()
{
	dfs(1,1);memset(f,40,sizeof(f));
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=read();
	f[q[top=1]=ID(0,id[0][0][0][0],1)]=0;
	for(int i=1;i<=top;++i)
	{
		int x=q[i]/MX/10,y=(q[i]/10)%MX,z=q[i]%10,v=f[q[i]];
		if(z<9) Try(x,y,z+1,v+1);
		if(z>1) Try(x,y,z-1,v+1);
		int nn=0;
		for(int j=1;j<=num[y];++j)
			if(c[y][j]!=z) A[++nn]=c[y][j];
		for(int j=nn+1;j<=4;++j) A[j]=0;
		Try(x,id[A[1]][A[2]][A[3]][A[4]],z,v+(num[y]-nn));
		if(x<n&&a[x+1]==z&&num[y]<4)
		{
			int nn=0,k=1;
			for(;k<=num[y];++k)
				if(c[y][k]<=b[x+1]) A[++nn]=c[y][k];
				else break;
			A[++nn]=b[x+1];
			for(;k<=num[y];++k) A[++nn]=c[y][k];
			while(nn<4) A[++nn]=0;
			Try(x+1,id[A[1]][A[2]][A[3]][A[4]],z,v+1); 
		}
	}
	for(int i=1;i<=9;++i) ans=min(ans,f[ID(n,id[0][0][0][0],i)]);
	cout<<ans;
	return 0;
}