#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 110
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,K,x,u,an;
int f[N][30][N],a[N][N];
char p[N];
inline int read() {
	char s[2];
	scanf("%s",s);
	return s[0]-'a'+1;
}
int main() {
	scanf("%s%d",p+1,&K);
	n=strlen(p+1);
	scanf("%d",&m);
	For(i,1,m) {
		int A=read(),B=read();
		scanf("%d",&k);
		a[A][B]=k;
	}
	memset(f,130,sizeof(f));
	an=f[0][0][0];
	f[0][0][0]=0;
	For(i,0,n-1)For(j,0,26)For(k,0,K) if ((x=f[i][j][k])>=-1e8) {
		int A=p[i+1]-'a'+1;
		For(u,1,26) {
			int B=k+(u!=A);
			if (B>K) continue;
			f[i+1][u][B]=max(f[i+1][u][B],x+a[j][u]);
		}
	}
	For(j,0,26)For(k,0,K) an=max(an,f[n][j][k]);
	printf("%d\n",an);
	return 0;
}