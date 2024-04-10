#include<cstdio>
#include<cstring>

using namespace std;

const char iname[]="input.txt";
const char oname[]="output.txt";
const int maxn=500;

int n,i,j,k,po[maxn],a[maxn][maxn];
char s[maxn][maxn];

void fill(int x,int y,int v)
{
	for(int i=x;i<x+v;++i)
		for(int j=y;j<y+v;++j)
			a[i][j]=1;
}

void color(int x,int y,int k)
{
	if(k==0)
		return;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(s[i][j]=='*')
				fill(x+(i-1)*po[k-1],y+(j-1)*po[k-1],po[k-1]);
			else
				color(x+(i-1)*po[k-1],y+(j-1)*po[k-1],k-1);
}

int main()
{
	freopen(iname,"r",stdin);
	freopen(oname,"w",stdout);
	scanf("%d%d\n",&n,&k);
	for(i=1;i<=n;++i)
		fgets(s[i]+1,sizeof(s[i]),stdin);
	po[0]=1;
	for(i=1;i<=k;++i)
		po[i]=po[i-1]*n;

	color(1,1,k);
	for(i=1;i<=po[k];++i)
	{
		for(j=1;j<=po[k];++j)
			if(a[i][j]==0)
				printf(".");
			else
				printf("*");
		printf("\n");
	}
}