#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[55][22];
int n,m,num[1<<20];
double f[1<<20],g[1<<20],ans=0; 
bitset<55> b[1<<20];

int main()
{
	n=read();
	for(int i=1;i<=n;++i) scanf("%s",st[i]+1);
	m=strlen(st[1]+1);f[0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j) if(i!=j)
		{
			int res=0;
			for(int k=1;k<=m;++k) if(st[i][k]==st[j][k]) res|=1<<k-1;	
			b[res][i]=1;
		}	
	}
	for(int i=(1<<m)-1;~i;--i)for(int j=0;j<m;++j) if(i&(1<<j)) b[i^(1<<j)]|=b[i];
	for(int i=0;i<1<<m;++i)
	{
		num[i]=i?num[i>>1]+(i&1):0;ans+=b[i].count()*f[i]/n;
	//	cout<<i<<" "<<f[i]<<" "<<b[i].count()<<endl;
		for(int j=0;j<m;++j) if(!(i&(1<<j))) f[i|(1<<j)]+=f[i]/(m-num[i]);
	}
	printf("%.10lf\n",ans);
	return 0;
}