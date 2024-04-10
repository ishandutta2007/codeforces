#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];
int n,f[MN+5][2][2][2],ans;
inline void R(int&x,int y){y>x?x=y:0;}
int main()
{
	n=read();scanf("%s",st+1);
	memset(f,200,sizeof(f));
	f[0][0][0][0]=f[0][1][0][0]=0;
	for(int i=1;i<=n;++i) for(int j=0;j<2;++j)
		for(int k=0;k<2;++k) for(int l=0;l<2;++l) if(f[i-1][j][k][l]>=0)
			for(int m=0;m<2;++m)
			{
				if(l&&!k&&m) continue;
			//	printf("f[%d][%d][%d][%d]=%d\n",i-1,j,k,l,f[i-1][j][k][l]);
				R(f[i][j][m][l|m],f[i-1][j][k][l]);
				if((st[i]-'0')^m^j) R(f[i][(st[i]-'0')^m][m][l|m],f[i-1][j][k][l]+1);
			}
	for(int j=0;j<2;++j) for(int k=0;k<2;++k) for(int l=0;l<2;++l)
		R(ans,f[n][j][k][l]);
	cout<<ans;
	return 0;
}