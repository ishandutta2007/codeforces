#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
inline int read(void) {
	int x = 0, c = 0, f = 1;
	for(;c<'0'||c>'9';c=getchar())f=c!='-';
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return f ? x : -x;
}
const int N = 110;
int n, m, a[N][N];
bool judge(int x,int p,int b) {
	if (b == 1) {
		for (int i = 1; i <= n; i++)
			if (!a[i][x]) return 0;
		for (int i = 1; i <= n; i++)
			a[i][x] -= p;
		return 1;
	} else {
		for (int i = 1; i <= m; i++)
			if (!a[x][i]) return 0;
		for (int i = 1; i <= m; i++)
			a[x][i] -= p;
		return 1;
	}
}
int x, y, now, ans,Index;
bool check() {
	now = INF;
	for (int i = 1; i <= n && now != 1; i++)
		for (int j = 1; j <= m && now != 1; j++)
			if (a[i][j] && a[i][j] < now) 
				now = a[i][j], x = i, y = j;
	return now != INF;
}
inline void ohno(void){cout << "-1" << endl;exit(0);}
struct node{
	int x, t, c;
}e[156115];
int main() {
	n = read(), m = read();
	int tot = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			tot += a[i][j] = read();
	int ans = 0;
	while (check()) {
		ans += a[x][y];
		if (n > m) {
			if (judge(y, a[x][y], 1)) {
				e[++Index] = (node){1,y,now};
				continue;
			} else if (judge(x, a[x][y], 0)){
				e[++Index] = (node){0,x,now};
				continue;
			}
		} else { 
			if (judge(x, a[x][y], 0)){
				e[++Index] = (node){0,x,now};
				continue;
			}
			else if (judge(y, a[x][y], 1) ) {
				e[++Index] = (node){1,y,now};
				continue;
			}
		}
		ohno();
	}
	printf("%d\n",ans);
	for (int i = 1; i <= Index; i++) {
		for (int j = 1; j <= e[i].c; j++)
			printf("%s %d\n",e[i].x?"col":"row",e[i].t);
	}
}