#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 2500550
int d,s;
queue<int>Q;
#define mp(x,y) (x*(s+1)+y)
int vis[N],ans[N];
int main() {
	scanf("%d%d",&d,&s);
	int i,tot=0;
	for(i=1;i<10&&i<=s;i++) {
		Q.push(mp(i%d,i));
		vis[mp(i%d,i)]=-1;
	}
	while(!Q.empty()) {
		int x=Q.front()/(s+1),y=Q.front()%(s+1); Q.pop();
		if(!x&&y==s) {
			int t=mp(x,y);
			while(1) {
				int nxt=vis[t];
				if(nxt==-1) break;
				ans[++tot]=t%(s+1)-nxt%(s+1);
				t=nxt;
			}
			ans[++tot]=t%(s+1);
			for(i=tot;i;i--) {
				printf("%d",ans[i]);
			}
			puts("");
			return 0;
		}
		for(i=0;i<10&&i+y<=s;i++) {
			int nx=(x*10+i)%d,ny=y+i;
			if(!vis[mp(nx,ny)]) {
				vis[mp(nx,ny)]=mp(x,y);
				Q.push(mp(nx,ny));
			}
		}
	}
	puts("-1"); 
	return 0;
}