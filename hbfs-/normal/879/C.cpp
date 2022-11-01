#include <bits/stdc++.h>
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int n,mark[105];
int main() {
	n = rd();
	for (int _=0;_<=10;_++) mark[_] = 1;
	for (int i=1;i<=n;i++) {
		char c[10]; int x;
		scanf("%s%d",c+1,&x);
		if (c[1] == '^') {
			for (int _=0;_<10;_++) {
				if (x&1) {
					if (mark[_] <= 2)
						mark[_] = 3-mark[_];
					else
						mark[_] = 7-mark[_];
				}
				x >>= 1;
			}
		}
		
		if (c[1] == '&') {
			for (int _=0;_<10;_++) {
				if ((x&1) == 0) mark[_] = 3;
				x >>= 1;
			}
		}
		
		if (c[1] == '|') {
			for (int _=0;_<10;_++) {
				if (x&1) mark[_] = 4;
				x >>= 1;
			}
		}
		
	}
	
	int cur = 0;	
	printf("%d\n",3);
	
	cur = 0;
	for (int _=0;_<10;_++)
		if (mark[_] == 2) cur += 1<<_;
	printf("^ %d\n",cur);
	
	cur = 0;
	for (int _=0;_<10;_++)
		if (mark[_] == 3) cur += 0; else cur += 1<<_;
	printf("& %d\n",cur);
	
	cur = 0;
	for (int _=0;_<10;_++)
		if (mark[_] == 4) cur += 1<<_; else cur += 0;
	printf("| %d\n",cur);
	return 0;
}