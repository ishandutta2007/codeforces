#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
int t[maxn],x[maxn],f[maxn][maxn][2];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",t+i,x+i);
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int at=0;at<2;at++) {
				if(f[i][j][at]>1e9)continue;
				if(i==n||(i==n-1&&j==n)) {
					puts("YES");
					return 0;
				}
				int st=at?j:i,to=j==i+1?i+2:i+1,tim=f[i][j][at];
				if(to<=n&&abs(x[st]-x[to])+tim<=t[to]) {
					if(j<=to)f[to][0][0]=min(f[to][0][0],t[to]);
					else f[to][j][0]=min(f[to][j][0],t[to]);
				}
				if(i==j||j==i+1) {
					for(int k=j+1;k<=n;k++) {
						int tmp=max(tim+abs(x[k]-x[st]),t[j]);
						if(tmp<=t[k])f[j][k][1]=min(f[j][k][1],tmp);
					}
				}
			}
	puts("NO");
	return 0;
}