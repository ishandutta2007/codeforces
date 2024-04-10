#include <bits/stdc++.h>
#define N 105
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
int n,m,mp[N][N],vis[N][N],pre[N][N],o[N*N],L,tx,ty;
char s[N],ch[5];

const int fx[] = {0,0,1,-1};
const int fy[] = {1,-1,0,0};

inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

void init() {
	n = rd(), m = rd();
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) {
			if (s[j] == '.' || s[j] == 'F') mp[i][j] = 1;
			if (s[j] == 'F') tx = i, ty = j;
		}
	}
}

void BFS() {
	queue<pii> q; q.push(pii(1,1)); vis[1][1] = 1;
	while (!q.empty()) {
		pii u = q.front(); q.pop();
		if (u.fi == tx && u.se == ty) break;
		pii v;
		for (int i=0;i<4;i++) {
			v.fi = u.fi + fx[i];
			v.se = u.se + fy[i];
			if (!mp[v.fi][v.se] || vis[v.fi][v.se]) continue;
			vis[v.fi][v.se] = 1;
			pre[v.fi][v.se] = i;
			q.push(v);
		}
	}
}

int main() {
	init();
	BFS();
	int nx, ny;
	nx = tx, ny = ty;
	while (nx != 1 || ny != 1) {
		int i = o[++L] = pre[nx][ny];
		nx += fx[i^1], ny += fy[i^1];
	}

	ch[0] = 'R'; ch[1] = 'L';
	ch[2] = 'D'; ch[3] = 'U';
	nx =1, ny = 1;
	for (int i=L;i>=1;i--) {
		printf("%c\n",ch[o[i]]); fflush(stdout);
		int gx = rd(), gy = rd();
		if (gx == nx && gy == ny)
			swap(ch[o[i]], ch[o[i]^1]), i++;
		else
			nx = gx, ny = gy;
	}
	return 0;
}