#include <iostream>
#include <cstdio>

using namespace std;

int F[100],cnt,vis[1000],v[1000];

int main()
{
	int a,b;
	for (int i=0;i<=9;i++) {
			printf("%d%d%d%d\n",i,i,i,i); fflush(stdout);
			scanf("%d%d",&a,&b);
			if (a > 0 || b > 0) F[++cnt] = i;
		}
		
	bool flag = true;
	for (int i=1;i<=4 && flag;i++) if (!vis[i]) {
		vis[i] = 1;
		v[i] = F[1];
		for (int j=1;j<=4 && flag;j++) if (!vis[j]) {
			vis[j] = 1;
			v[j] = F[2];
			for (int p1=1;p1<=4 && flag;p1++) if (!vis[p1]) {
				vis[p1] = 1;
				v[p1] = F[3];
				for (int p2=1;p2<=4 && flag;p2++) if (!vis[p2]) {
					vis[p2] = 1;
					v[p2] = F[4];
					printf("%d%d%d%d\n",v[1],v[2],v[3],v[4]);  fflush(stdout);
					scanf("%d%d",&a,&b);
					if (a == 4) flag = false;
					vis[p2] = 0;
				}
				vis[p1] = 0;
			}
			vis[j] = 0;
		}
		vis[i] = 0;
	}
	return 0;
}