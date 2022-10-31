#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline char nc() {
	static char buf[100000],*p1,*p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
int rd() {
	int x=0; char ch=nc();
	while(ch<'0'||ch>'9') ch=nc();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=nc();
	return x;
}
#define N 4050
int n,K,s[N][N],f[N],g[N],C;
int Y(int j,int i) {
	return f[j]+(s[j][j]+s[i][i]-s[i][j]*2)/2+C;
}
struct A {
	int l,r,p;
}Q[N];
int find(const A &a,int x) {
	int l=a.l,r=a.r+1;
	while(l<r) {
		int mid=(l+r)>>1;
		if(Y(x,mid)>Y(a.p,mid)) l=mid+1;
		else r=mid;
	}
	return l;
}
void check() {
	int i;
	int l=0,r=0;
	f[0]=0; g[0]=0;
	Q[r++]=(A){0,n,0};
	for(i=1;i<=n;i++) {
		while(l<r&&Q[l].r<i) l++;
		f[i]=Y(Q[l].p,i); g[i]=g[Q[l].p]+1;
		if(Y(i,n)<=Y(Q[r-1].p,n)) {
			while(l<r&&Y(i,Q[r-1].l)<=Y(Q[r-1].p,Q[r-1].l)) r--;
			if(l==r) Q[r++]=(A){i,n,i};
			else {
				int x=find(Q[r-1],i);
				Q[r-1].r=x-1;
				Q[r++]=(A){x,n,i};
			}
		}
	}
}
int main() {
	n=rd(); K=rd();
	register int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			s[i][j]=rd();
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	int l=0,r=1<<30;
	while(l<r) {
		C=(l+r)>>1;
		check();
		if(g[n]>K) l=C+1;
		else r=C;
	}
	l--;
	C=l; check();
	printf("%d\n",f[n]-K*l);
}