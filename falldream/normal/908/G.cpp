#include<bits/stdc++.h>
#define MN 700
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[MN+5];
int n,f[MN+5][MN+5][2],g[MN+5][MN+5][2],pw[MN+5],ans;
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
void Solve(int mid)
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));f[0][0][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<i;++j) for(int l=0;l<2;++l) if(f[i-1][j][l]|g[i-1][j][l])
		{
			for(int k=0;k<10;++k)
			{
				if(l&&k>s[i]-'0') continue;
				int nl=l&(k==s[i]-'0');
				if(k==mid) 
					R(f[i][j+1][nl],f[i-1][j][l]),
					R(g[i][j+1][nl],(g[i-1][j][l]+1LL*pw[j]*f[i-1][j][l]%mod*mid)%mod);
				else if(k<mid) 
					R(f[i][j][nl],f[i-1][j][l]),
					R(g[i][j][nl],g[i-1][j][l]);
				else
					R(f[i][j+1][nl],f[i-1][j][l]),
					R(g[i][j+1][nl],10LL*g[i-1][j][l]%mod);
			}
		}
	for(int j=0;j<=n;++j) for(int l=0;l<2;++l) R(ans,g[n][j][l]);
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);pw[0]=1;
	for(int i=1;i<=n;++i) pw[i]=10LL*pw[i-1]%mod;
	for(int i=1;i<=9;++i) Solve(i);
	printf("%d\n",ans);
	return 0;
}