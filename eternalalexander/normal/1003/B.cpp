#include <cstdio>

int main() {
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	if (n%2==1) {
		for (int i=1;i<=a-n/2-1;++i) printf("0");
		for (int i=1;i<=n/2+1;++i) printf("01");
		for (int i=1;i<=b-n/2-1;++i) printf("1");
	} else {
			if (a-n/2>0) {
				
				for (int i=1;i<=n/2;++i) printf("01");for (int i=1;i<=b-n/2;++i) printf("1");
				for (int i=1;i<=a-n/2;++i) printf("0");
					
			}else {
				for (int i=1;i<=n/2;++i) printf("10");
				for (int i=1;i<=b-n/2;++i) printf("1");
			}
		}
	return 0;
}