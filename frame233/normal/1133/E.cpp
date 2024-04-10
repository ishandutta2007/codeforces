#include<cstdio>
#include<algorithm>
#include<cstring>
const int N=5005;
int f[N][N],a[N];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	memset(f,255,sizeof(f));
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for(int i=0;i<=k;++i) f[1][i]=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			if(~f[i][j])
			{
				int pos=std::upper_bound(a+1,a+n+1,a[i]+5)-a;
				f[i+1][j]=max(f[i+1][j],f[i][j]);
				f[pos][j+1]=max(f[pos][j+1],f[i][j]+pos-i);
			}
		}
	}
	printf("%d\n",f[n+1][k]);
	return 0;
}