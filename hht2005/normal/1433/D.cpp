#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int fl=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=n;i++)
			if(a[i]!=a[1])fl=1;
		if(fl) {
			puts("YES");
			int j=-1;
			for(int i=1;i<=n;i++)
				if(a[i]!=a[1])printf("%d %d\n",1,j=i);
			for(int i=2;i<=n;i++)
				if(a[i]==a[1])printf("%d %d\n",i,j);
		} else puts("NO");
	}
	return 0;
}