#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int main() {
	int a,b,k;
	scanf("%d%d%d",&b,&a,&k);
	if(b==0) {
		if(k==0) {
			puts("Yes");
			for(int i=1;i<=a;i++)putchar('1');puts("");
			for(int i=1;i<=a;i++)putchar('1');puts("");
		}
		else puts("No");
		return 0;
	}
	if(a+b-k<=1) {
		puts("No");
		return 0;
	}
	if(a==1) {
		if(k==0) {
			puts("Yes");
			putchar('1');
			for(int i=1;i<=b;i++)
				putchar('0');
			puts("");
			putchar('1');
			for(int i=1;i<=b;i++)
				putchar('0');
			puts("");
		} else puts("No");
		return 0;
	}
	puts("Yes");
	int cnt=0;
	for(int i=1;i<=a+b;i++) {
		if(i==a+b-k)putchar('1');
		else {
			if(cnt<a-1)putchar('1'),cnt++;
			else putchar('0');
		}
	}
	puts("");
	cnt=0;
	for(int i=1;i<a+b;i++) {
		if(i==a+b-k)putchar('0');
		else {
			if(cnt<a-1)putchar('1'),cnt++;
			else putchar('0');
		}
	}
	puts("1");
	return 0;
}