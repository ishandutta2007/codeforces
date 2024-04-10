#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 300050
int n,a[N],f[N],c[N];
int gcd(int x,int y) {
	return y?gcd(y,x%y):x;
}
inline void upd(int &x,int y) {x=x<y?x:y;}
void solve() {
	scanf("%d",&n);
	register int i,j,x,lim;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	// if(n==20000) {
	// 	puts("4"); return ;
	// }
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(i=1;i<=n;i++) c[a[i]]=1;
	for(i=1;i<=300000;i++) {
		if(c[i]) {
			for(j=i+i;j<=300000;j+=i) c[j]=0;
		}
	}
	n=0;
	for(i=1;i<=300000;i++) if(c[i]) a[++n]=i;
	
	

	int tmp=0;
	for(i=1;i<=n;i++) {
		tmp=gcd(tmp,a[i]);
		if(a[i]==1) {puts("1"); return ;}
	}
	if(tmp>1) {puts("-1"); return ;}
	
	if(n<=20000) {
		for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) {
			if(gcd(a[i],a[j])==1) {
				puts("2"); return ;
			}
		}
	}
	
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(i=1;i<=n;i++) {
		x=a[i];
		lim=a[i-1];
		for(j=0;j<=lim;j++) {
			if( f[j] <n) upd(f[ gcd(x,j) ],f[j]+1);
		}
	}
	if(f[1]>n) puts("-1");
	else printf("%d\n",f[1]);
}
int main() {
	solve();
	return 0;
}