#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 100010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	int x,y;
} b[N*2];
int i,j,k,n,m,dian,t;
int id[N],a[N],rank[N];
inline bool ju(int x) {
	for (;x;x/=10) {
		int A=x%10;
		if (A!=4&&A!=7) return 0;
	}
	return 1;
}
inline void pan() {
	int F=0;
	For(i,1,n) if (ju(a[i])) F=1;
	if (F) return;
	For(i,1,n-1) if (a[i]>a[i+1]) {
		printf("-1\n");
		exit(0);
	}
	printf("0\n");
	exit(0);
}
inline bool cc1(const int &A,const int &B) {
	return a[A]<a[B];
}
inline void huan(int &x,int y) {
	if (x==y) return;
	b[++t]=(ww){x,y};
	swap(id[rank[x]],id[rank[y]]);
	swap(rank[x],rank[y]);
	x=y;
}
int main() {
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),id[i]=i;
	pan();
	sort(id+1,id+n+1,cc1);
	For(i,1,n) rank[id[i]]=i;
	For(i,1,n) if (ju(a[i])) dian=i;
	For(i,1,n) {
		if (id[i]==i) continue;
		huan(dian,i);
		huan(dian,id[i]);
	}
	//For(i,1,n) printf("%d ",rank[i]);
	//printf("\n");
	printf("%d\n",t);
	For(i,1,t) printf("%d %d\n",b[i].x,b[i].y);
	return 0;
}