#include<iostream>
#include<cstdio>
#define ull unsigned long long
#define MN 200000
#define MB 450
#define MX 100
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int block[MN+5],n,m,a[MN+5],t[MX+5],p[(1<<15)+5];
struct Bitset
{
	ull a[2];
	void Set(int x){a[x>>6]|=1ULL<<(x&63);}
	void Clear(){a[0]=a[1]=0;}
	void Change(int z)
	{
		int add=64,y;ull x;
		for(x=a[1];x;)
			if(x&65535) y=x&65535,y=y&(-y),t[p[y]+add]=z,x^=y;
			else x>>=16,add+=16;
		for(x=a[add=0];x;)
			if(x&65535) y=x&65535,y=y&(-y),t[p[y]+add]=z,x^=y;
			else x>>=16,add+=16;
	}
	void operator |=(const Bitset&y){a[0]|=y.a[0];a[1]|=y.a[1];}
}s[MB+5][MX+5];
void Rebuild(int x)
{
	int l=x*MB-MB+1,r=min(n,x*MB);
	for(int i=1;i<=MX;++i) s[x][i].Change(i),s[x][i].Clear(),s[x][i].Set(i);
	for(int i=l;i<=r;++i) a[i]=t[a[i]]; 
}
int main()
{
	for(int i=1,j=0;j<16;++j,i<<=1) p[i]=j;
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),block[i]=(i-1)/MB+1;
	m=read();
	for(int i=1;i<=block[n];++i) for(int j=1;j<=MX;++j) s[i][j].Set(j);
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read(),x=read(),y=read();
		if(x==y) continue;Rebuild(block[l]);
		for(int i=l;i<=r&&block[i]==block[l];++i) if(a[i]==x) a[i]=y;
		if(block[l]!=block[r])
		{
			Rebuild(block[r]);
			for(int i=r;block[i]==block[r];--i) if(a[i]==x) a[i]=y;
		}
		for(int i=block[l]+1;i<block[r];++i) s[i][y]|=s[i][x],s[i][x].Clear();
	}
	for(int i=1;i<=block[n];++i) Rebuild(i);
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}