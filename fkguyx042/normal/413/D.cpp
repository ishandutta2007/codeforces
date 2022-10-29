#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 2050
#define mo 1000000007
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,nn,mm,an;
int f[N][N];
inline void Do(int x,int y) {
	f[i][x]+=y;
	if (f[i][x]>=mo) f[i][x]-=mo;
}
int main() {
	scanf("%d%d",&n,&m);
	nn=(1<<m)-1; mm=(1<<m-1)-1;
	f[0][0]=1;
	For(i,1,n) {
		scanf("%d",&k);
		For(j,0,nn) if (f[i-1][j]) {
			int A=j>>m-1&1,B=j&mm;
			if (!k||k==2) Do(B+1|A<<m-1,f[i-1][j]);
			if (!k||k==4) {
				if (B&1) Do(2|A<<m-1,f[i-1][j]);
				else Do(B+2|A<<m-1,f[i-1][j]);
			}
		}
	}
	For(j,0,nn) if (j>>m-1&1) an=(an+f[n][j])%mo;
	printf("%d\n",an);
	return 0;
}