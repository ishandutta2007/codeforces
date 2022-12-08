#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		int v=0;
		for(int i=2;i<=n;i++)
			if(a[i]<a[i-1])v+=a[i-1]-a[i];
		puts(v<=a[1]?"YES":"NO");
	}
	return 0;
}