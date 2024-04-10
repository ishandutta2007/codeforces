#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
inline int read(void) {
	int x = 0, c = 0, f = 1;
	for(;c<'0'||c>'9';c=getchar())f=c!='-';
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
const int N = 1100;
int a[N], b[N], n, c[N];
int q[N], r,vis[N];
void print(){for(int i=1;i<=n;i++)printf("%d%c",c[i]," \n"[i==n]);exit(0);}
bool judge(){
	static bool no[N];
	memset(no,0,sizeof no);
	for(int i=1;i<=n;i++)
		if(no[c[i]])return 0;
		else no[c[i]]=1;
	return 1;
}
inline int calc(void) {
	static int i=1;
	if(i==n)i=1;
	for(;i<=n;i++)
		if(!vis[i])return i;
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++) 
		a[i] = read();
	for (int i = 1; i <= n; i++) {
		b[i] = read();
		if (b[i] != a[i]) q[++r] = i;
		else c[i] = a[i], vis[a[i]]=1;
	}
	if (r == 1) {
		c[q[1]] = a[q[1]];
		if (judge()) print();
		c[q[1]] = b[q[1]];
		if(judge()) print();
		c[q[1]] = calc();
		if(judge()) print();
	}
	else if (r == 2) {
		c[q[1]] = a[q[1]], c[q[2]] = a[q[2]];
		if(judge())print();
		c[q[1]] = b[q[1]], c[q[2]] = a[q[2]];
		if(judge())print();
		c[q[1]] = a[q[1]], c[q[2]] = b[q[2]];
		if(judge())print();
		c[q[1]] = b[q[1]], c[q[2]] = b[q[2]];
		if(judge())print();
	}
}