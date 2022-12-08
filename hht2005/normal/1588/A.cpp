#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N],b[N];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=n;i++)scanf("%d",b+i);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int FL=1;
		for(int i=1;i<=n;i++) {
			if(a[i]==b[i])continue;
			if(a[i]>b[i])FL=0;
			if(a[i]<b[i]-1)FL=0;
		}
		puts(FL?"YES":"NO");
	}
	return 0;
}