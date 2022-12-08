#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int cnt=1;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			if(a[i]<=i)cnt=i+1;
		printf("%d\n",cnt);
	}
	return 0;
}