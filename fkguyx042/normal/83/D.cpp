#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 30000000
#define int64 long long
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,F,l,r,K,an;
int f[N],p[N];
void dfs(int x,int64 y,int phi) {
	if (y>n) return;
	if (x>m) {
		an+=phi*(n/y);
		return;
	}
	dfs(x+1,y,phi);
	dfs(x+1,y*p[x],-phi);
}
inline int cal(int x) {
	n=x/K;
	if (F) return 0;
	int i;
	an=0;
	if (n<N) {
		For(i,1,n) if (i==1||f[i]>=K) an++;
	} else {
		For(i,1,*p) if (p[i]==K) break;
		m=i-1;
		dfs(1,1,1);
	}
	return an;
}
int main() {
	For(i,2,N-1) {
		if (!f[i]) f[i]=p[++*p]=i;
		for (j=1;j<=*p&&p[j]<=f[i]&&i*p[j]<N;j++) f[i*p[j]]=p[j];
	}
	scanf("%d%d%d",&l,&r,&K);
	for (i=2;i*i<=K;i++) if (K%i==0) {
		F=1; break;
	}
	printf("%d\n",cal(r)-cal(l-1));
	return 0;
}