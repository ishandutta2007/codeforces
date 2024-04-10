#include <bits/stdc++.h>
#define N 1000500
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int n,q,c;
int x[N],y[N],s[N];
int sum[15][105][105], a[105][105];

int main() {
	n = rd(), q = rd(), c = rd(); c++;
	for (int i=1;i<=n;i++) x[i] = rd(), y[i] = rd(), s[i] = rd();
	for (int _=1;_<=c;_++) {
		for (int i=1;i<=n;i++) s[i] = (s[i]+1) % c;
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++) a[ x[i] ][ y[i] ] += s[i];
		for (int i=1;i<=100;i++)
			for (int j=1;j<=100;j++)
				sum[_][i][j] = sum[_][i-1][j] + sum[_][i][j-1] - sum[_][i-1][j-1] + a[i][j];
	}
	while (q--) {
		int t = rd(), xx1 = rd(), yy1 = rd(), xx2 = rd(), yy2 = rd();
		t%=c; if (!t) t=c;
		int ans = sum[t][xx2][yy2] - sum[t][xx2][yy1-1] - sum[t][xx1-1][yy2] + sum[t][xx1-1][yy1-1];
		printf("%d\n",ans);
	}
	return 0;
}