#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int cmd,h,m;
	scanf("%d",&cmd);
	scanf("%d:%d",&h,&m);
	m = m % 60;
	if (cmd == 12) {
		if (h == 0) h = 10;
		if (h > 12) {
			if (h % 10 == 0) h = 10; else h = h % 10;
		}
	} else {
		if (h >= 24) {h %= 10;}
	}
	if (h < 10) printf("0%d:",h); else printf("%d:",h);
	if (m < 10) printf("0%d\n",m); else printf("%d\n",m);
	return 0;
}