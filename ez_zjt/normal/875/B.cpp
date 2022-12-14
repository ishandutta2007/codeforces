#include <cstdio>
#include <cstring>
#define MAXN 1000100

int n,sizew;
int q[MAXN];
int p[MAXN][2];

void merge(int x,int y){
	p[p[x][0]][1]=p[y][1];
	p[p[y][1]][0]=p[x][0];
}

int gao(int x){
	static int cnt=0;
	cnt++;
	p[x][0]=p[x][1]=x;
	if(p[x+1][0]) merge(x,x+1);
	if(p[x-1][0]) merge(x-1,x);
	if(!p[n][0]) return cnt;
	return cnt-(n-p[n][0]+1);
}

int main(){
#ifdef DEBUG
	freopen("B.in","r",stdin);
#endif
	scanf("%d",&n);
	for(sizew=1;sizew<n;sizew<<=1);
	printf("1 ");
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		printf("%d ",gao(t)+1);
	}
}