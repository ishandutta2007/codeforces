#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 100010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	char p[30];
	int a;
	inline void read() {
		scanf("%s",p+1);
		scanf("%d",&a);
	}
	inline bool operator < (const ww &A) const {
		int i;
		if (a>A.a) return 1;
		if (a<A.a) return 0;
		For(i,1,20) {
			if (p[i]<A.p[i]) return 1;
			if (p[i]>A.p[i]) return 0;
		}
		return 1;
	}
} a[N],c[N];
int i,j,k,n,m;
int b[N];
char s[30];
inline int find() {
	scanf("%s",s+1);
	int i,j;
	For(i,1,n) {
		int F=0;
		For(j,1,20) if (a[i].p[j]!=s[j]) F=1;
		if (!F) return i;
	}
}
inline void work1(int x) {
	int i,an=0;
	For(i,1,n) c[i]=a[i];
	c[x].a+=b[1];
	int j=2;
	for (i=n;i;i--) if (i!=x) {
		for (;j<=n;j++) {
			c[i].a+=b[j];
			if (c[x]<c[i]) break;
			c[i].a-=b[j];
		}
		if (j<=n) an++,j++;
	}
	printf("%d ",n-an);
}
inline void work2(int x) {
	int i,an=0;
	For(i,1,n) c[i]=a[i];
	c[x].a+=b[n];
	int j=n-1;
	For(i,1,n) if (i!=x) {
		for (;j;j--) {
			c[i].a+=b[j];
			if (c[i]<c[x]) break;
			c[i].a-=b[j];
		}
		if (j) an++,j--;
	}
	printf("%d\n",an+1);
}
int main() {
	scanf("%d",&n);
	For(i,1,n) a[i].read();
	scanf("%d",&m);
	For(i,1,m) scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	sort(a+1,a+n+1);
	int A=find();
	work1(A);
	work2(A);
	return 0;
}