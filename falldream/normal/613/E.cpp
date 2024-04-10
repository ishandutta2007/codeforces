#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 2000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char w[MN+5],s[2][MN+5];
int f[2][MN+5][MN+5],n,m,ans=0;
int pre[2][MN+5],suf[2][MN+5],Ha[MN+5],pw[MN+5];
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
void Solve()
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;++i) 
		pre[0][i]=(103LL*pre[0][i-1]+s[0][i])%mod,
		pre[1][i]=(103LL*pre[1][i-1]+s[1][i])%mod;
	for(int i=n;i;--i)
		suf[0][i]=(103LL*suf[0][i+1]+s[0][i])%mod,
		suf[1][i]=(103LL*suf[1][i+1]+s[1][i])%mod;
	for(int i=1;i<=m;++i) Ha[i]=(103LL*Ha[i-1]+w[i])%mod,pw[i]=103LL*pw[i-1]%mod;
	for(int i=1;i<=n;++i)
	{
		f[0][i-1][0]=f[1][i-1][0]=1;	
		for(int j=0;j<m;++j)
		{
			if(s[0][i]==w[j+1]) R(f[0][i][j+1],f[0][i-1][j]);
			if(s[1][i]==w[j+1]) R(f[1][i][j+1],f[1][i-1][j]);
			if(s[0][i]==w[j+1]&&s[1][i]==w[j+2]) R(f[1][i][j+2],f[0][i-1][j]);
			if(s[1][i]==w[j+1]&&s[0][i]==w[j+2]) R(f[0][i][j+2],f[1][i-1][j]);
		}
		for(int j=i-1;j;--j)
		{
			int len=i-j+1;
			if(len<<1>m) continue;
			int ul=(pre[0][i]-1LL*pre[0][j-1]*pw[len]%mod+mod)%mod;
			int ur=(suf[0][j]-1LL*suf[0][i+1]*pw[len]%mod+mod)%mod;
			int dl=(pre[1][i]-1LL*pre[1][j-1]*pw[len]%mod+mod)%mod;
			int dr=(suf[1][j]-1LL*suf[1][i+1]*pw[len]%mod+mod)%mod;
			int ha1=Ha[len],ha2=(Ha[len<<1]-1LL*Ha[len]*pw[len]%mod+mod)%mod;
			if(dr==ha1&&ul==ha2) R(f[0][i][len<<1],(len<<1)==m?mod+1>>1:1);
			if(ur==ha1&&dl==ha2) R(f[1][i][len<<1],(len<<1)==m?mod+1>>1:1);
		}
		R(ans,f[0][i][m]);R(ans,f[1][i][m]);
		for(int j=i+1;j<=n;++j) 
		{
			int len=j-i+1;
			if(len<<1>m) continue;
			int ul=(pre[0][j]-1LL*pre[0][i-1]*pw[len]%mod+mod)%mod;	
			int ur=(suf[0][i]-1LL*suf[0][j+1]*pw[len]%mod+mod)%mod;
			int dl=(pre[1][j]-1LL*pre[1][i-1]*pw[len]%mod+mod)%mod;
			int dr=(suf[1][i]-1LL*suf[1][j+1]*pw[len]%mod+mod)%mod;
			int ha1=(Ha[m-len]-1LL*Ha[m-(len<<1)]*pw[len]%mod+mod)%mod; 
			int ha2=(Ha[m]-1LL*Ha[m-len]*pw[len]%mod+mod)%mod;
			if(ul==ha1&&dr==ha2) R(ans,1LL*((len<<1)==m?mod+1>>1:1)*f[0][i-1][m-(len<<1)]%mod);
			if(dl==ha1&&ur==ha2) R(ans,1LL*((len<<1)==m?mod+1>>1:1)*f[1][i-1][m-(len<<1)]%mod);
		}
	} 	
}
int main()
{
	scanf("%s",s[0]+1);scanf("%s",s[1]+1);n=strlen(s[0]+1);
	scanf("%s",w+1);m=strlen(w+1);pw[0]=1;
	
	if(m==1)
	{
		for(int i=1;i<=n;++i) R(ans,(s[0][i]==w[1])+(s[1][i]==w[1]));
		return 0*printf("%d\n",ans);	
	}
	
	if(m==2)
	{
		for(int i=1;i<=n;++i) for(int j=0;j<2;++j)
			if(s[j][i]==w[1])
			{
				if(s[j^1][i]==w[2]) ++ans;	
				if(i>1&&s[j][i-1]==w[2]) ++ans;
				if(i<n&&s[j][i+1]==w[2]) ++ans;
			}
		return 0*printf("%d\n",ans);
	}
	Solve();
	for(int j=0;j<2;++j) for(int l=1,r=n;l<r;++l,--r) swap(s[j][l],s[j][r]);
	Solve();
	printf("%d\n",ans);
	return 0;
}