#include <cstdio>
#include <cstring>
#define rep(i,a,n) for (int i=a;i<n;i++)
int l;
int main() {
	scanf("%d",&l);
	if (l&1) return puts("-1"),0;
	else {
		rep(i,0,l) {
			rep(j,0,l) {
				rep(k,0,l) putchar(((j/2)&1)^((k/2)&1)^(i&1)?'w':'b');
				puts("");
			}
			puts("");
		}
	}
}