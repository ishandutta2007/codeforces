#include<cstdio>
#include<cstring>
const int N=505;
char s[N];
int f[N][N];
inline int min(int a,int b){return a<b?a:b;}
int main()
{
	int n;
	scanf("%d %s",&n,s+1);
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;++i) f[i][i]=1;
	for(int len=2;len<=n;++len)
	{
		for(int i=1,j=len;j<=n;++i,++j)
		{
			if(s[i]==s[j])
			{
				f[i][j]=min(f[i+1][j],f[i][j-1]);
			}
			else
			{
				for(int k=i;k<j;++k)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}
//Dpair AK IOI
//Dpair bless me