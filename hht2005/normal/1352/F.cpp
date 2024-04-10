#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n1,n2,n3;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n1,&n2,&n3);
		if(n2==0) {
			if(n1)for(int i=1;i<=n1+1;i++)putchar('0');
			if(n3)for(int i=1;i<=n3+1;i++)putchar('1');
			puts("");
			continue;
		}
		for(int i=1;i<=n3+1;i++)putchar('1');
		for(int i=1;i<=n1+1;i++)putchar('0');
		for(int i=1;i<n2;i++)putchar('0'+(i&1));
		puts("");
	}
	return 0;
}