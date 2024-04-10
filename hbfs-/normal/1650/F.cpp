#include <bits/stdc++.h>
#define N 100050
#define INF (1LL<<62)
using namespace std;

struct Node{
	int e,p,t,id;	
}t[N];
bool cmp(Node p1, Node p2) {return p1.e < p2.e;}
int n, m, a[N], pre[N][105], ad[N][105], o[N];
long long F[N][105];

int main() {
	int T; scanf("%d",&T);
	while (T--) {
		bool flag = true;
		int tot = 0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=m;i++) {
			t[i].id = i;
			scanf("%d%d%d", &t[i].e, &t[i].t, &t[i].p);
		}
		sort(t+1, t+m+1, cmp);
		
		int k = 1;
		long long cur = 0;
		for (int i=1;i<=n;i++) {
			F[0][0] = 0;
			for (int j=1;j<=100;j++)
				F[0][j] = INF, pre[0][j] = 0, ad[0][j] = -1;
			int h = 0;
			while (k<=m && t[k].e==i) {
				h++;
				for (int j=0;j<=100;j++) {
					F[h][j] = F[h-1][j];
					ad[h][j] = -1;
					pre[h][j] = j;
				}
				for (int j=100;j>=0;j--) {
					int x = min(j+t[k].p, 100);
					if (F[h][x] > F[h-1][j] + t[k].t) {
						F[h][x] = F[h-1][j] + t[k].t;
						pre[h][x] = j;
						ad[h][x] = t[k].id;
					}
				}
				k++;
			}
			
			if (F[h][100]==INF) {
				puts("-1");
				flag = false;
				break;
			} else {
				int x = 100, nh=h;
				while (x) {
					if (ad[nh][x]!=-1)
						o[++tot] = ad[nh][x];
					x = pre[nh][x];
					nh--;
				}
				cur += F[h][100];
				if (cur > a[i]) {
					puts("-1");
					flag = false;
					break;
				}
			}
		}
		if (!flag) continue;
		
		printf("%d\n", tot);
		for (int i=1;i<=tot;i++)
			printf("%d%c", o[i], i==tot?'\n':' ');
	}
	return 0;
}