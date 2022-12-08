#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n,m,a,b,c,d;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		int f=0;
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(b==c)f=1;
		}
		if((m&1)||!f)puts("NO");
		else puts("YES");
	}
	return 0;
}