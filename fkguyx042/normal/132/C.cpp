#include<cstdio>
#include<cstring>
#define rep(i,n) for (int i=0;i<n;i++)
#define Max(x,y) if (y>x) x=y
char s[105]; int n,m,ans,f[105][55][2];
int main()
{
	scanf("%s%d",s,&m),n=strlen(s); memset(f,200,sizeof(f)),f[0][0][0]=f[0][0][1]=0;
	rep(i,n) rep(j,m+1) rep(k,2){
		Max(f[i+1][j+(s[i]!='F')][k],f[i][j][k]+(k?1:-1));
		Max(f[i+1][j+(s[i]!='T')][!k],f[i][j][k]);
		}
	for (int i=m;i>=0;i-=2){Max(ans,f[n][i][0]); Max(ans,f[n][i][1]);}
	printf("%d\n",ans); return 0;
}