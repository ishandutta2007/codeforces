#include <cstdio>

int n, x, y;
int sum[200005][2];
char cmd[200005];

int abs(int x) {
	if (x>0) return x;
	else return -x;
}

bool check(int l) {
//	printf("checking:%d\n", l);
	for (int i=1;i+l-1<=n;++i) {
		int nx=sum[i-1][0]+sum[n][0]-sum[i+l-1][0];
		int ny=sum[i-1][1]+sum[n][1]-sum[i+l-1][1];
		int v=abs(nx-x)+abs(ny-y);
		if (v<=l&&v%2==l%2) return 1;
	//	printf("%d %d %d\n", i, l+i, v);
	}return 0;
}

int main() {
	scanf("%d %s %d %d", &n, cmd+1, &x, &y);
	if (abs(x)+abs(y)>n) {
		printf("-1");
		return 0;
	}
	sum[0][0]=sum[0][1]=0;
	for (int i=1;i<=n;++i) {
		sum[i][0]=sum[i-1][0];
		sum[i][1]=sum[i-1][1];
		if (cmd[i]=='U') sum[i][1]+=1;
		if (cmd[i]=='D') sum[i][1]-=1;
		if (cmd[i]=='L') sum[i][0]-=1;
		if (cmd[i]=='R') sum[i][0]+=1;
	//	printf("%c ", cmd[i]);
	}
	int l=0,r=n,ans=-1;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) {r=mid-1;ans=mid;}
		else l=mid+1;
	}printf("%d", ans);
	return 0;
}