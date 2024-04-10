#include <bits/stdc++.h>

int x[1005], y[1005], dx[1005], dy[1005], vx[1005], vy[1005], cnt[1005]={0};
int n;
struct node {
	int a, b;
};
std::map <node, int> mp;
node newnode(int a, int b) {node nd;nd.a=a;nd.b=b;return nd;}
bool operator < (node a, node b) {
	return a.a<b.a||(a.a==b.a&&a.b<b.b);
}
int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;++i) {
		scanf("%d %d", &x[i], &y[i]);
	} for (int i=1;i<=n;++i) scanf("%d %d", &dx[i], &dy[i]);
	for (int i=1;i<=n;++i) {
		vx[i]=x[1]+dx[i], vy[i]=y[1]+dy[i];
		//printf("%d %d\n", vx[i], vy[i]);
		mp[newnode(vx[i], vy[i])]++;
	}
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
			int px=x[i]+dx[j], py=y[i]+dy[j];
			//printf(">%d %d\n", px, py);
			node nd=newnode(px, py);
			if (mp.count(nd)) mp[nd]++;
		}
	}std::map<node, int>::iterator iter; 
	for(iter=mp.begin();iter!=mp.end();iter++) {
		if (iter->second==n+1) {
			printf("%d %d", iter->first.a, iter->first.b);
			return 0;
		}
	}
        
	return 0;
}