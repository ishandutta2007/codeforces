#include<iostream>
#include<cstdio>
#include<bitset>
#define MN 1000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int ans=0,n,m;
bitset<MN+5> r[MN+5],c[MN+5],R,C;
int main()
{
	n=read();
	for(int i=1,k;i<=n;++i)
		for(int j=1;j<=n;++j)
			k=read(),r[i][j]=k,c[j][i]=k;
	for(int i=1;i<=n;++i) ans+=(r[i]&c[i]).count();
	m=read();ans&=1;
	for(int i=1;i<=m;++i)
	{
		int op=read();
		if(op==3){printf("%d",ans);continue;}
		int x=read();
		if(op==1)
		{
			int cen=(r[x]^R)[x],h=((r[x]^R)&(c[x]^C)).count();
			ans-=(h-cen)*2+cen;r[x].flip();
			int Newh=((r[x]^R)&(c[x]^C)).count();
			ans+=(Newh-(cen^1))*2+(cen^1);
			C.flip(x);
		}	
		else 
		{
			int cen=(c[x]^C)[x],h=((r[x]^R)&(c[x]^C)).count();
			ans-=(h-cen)*2+cen;c[x].flip();
			int Newh=((r[x]^R)&(c[x]^C)).count();
			ans+=(Newh-(cen^1))*2+(cen^1);
			R.flip(x);
		}
		ans=(ans+(int)1e6)&1;
	}
	return 0;
}