#include <cstdio>
using namespace std;
char s[155];
int n,m;
int next[155][3],f[155][55][55][55];
const int Mod=51123987;
int ans=0;
inline int abs(int x)
{
	if (x<0) return -x;
	return x;
}
inline bool Check(int a,int b,int c)
{
	return a+b+c==n && abs(a-b)<=1 && abs(a-c)<=1 && abs(b-c)<=1;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	next[n+1][0]=next[n+1][1]=next[n+1][2]=n+1;
	for (int i=n;i;i--)
	{
		for (int j=0;j<3;j++) next[i][j]=next[i+1][j];
		next[i][s[i]-'a']=i;
	}
	m=(n+2)/3;
	f[1][0][0][0]=1;
	for (int i=1;i<=n;i++)
		for (int a=0;a<=m;a++)
			for (int b=0;b<=m;b++)
				for (int c=0;c<=m;c++)
				{
					if (Check(a,b,c))
					{
						(ans+=f[i][a][b][c])%=Mod;
						continue;
					}
					if (next[i][0]<=n) (f[next[i][0]][a+1][b][c]+=f[i][a][b][c])%=Mod;
					if (next[i][1]<=n) (f[next[i][1]][a][b+1][c]+=f[i][a][b][c])%=Mod;
					if (next[i][2]<=n) (f[next[i][2]][a][b][c+1]+=f[i][a][b][c])%=Mod;
				}
	printf("%d\n",ans);
	return 0;
}