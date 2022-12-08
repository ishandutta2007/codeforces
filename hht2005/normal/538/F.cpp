#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],d[N];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	if(a[1]>a[2])d[1]++;
	for(int i=3;i<=n;i++) {
		int L=i-2;
		for(int j=1,k;j<=L;j=k+1) {
			k=L/(L/j);
			if(a[L/j+1]>a[i])
				d[j]++,d[k+1]--;
		}
		if(a[1]>a[i])d[L+1]++;
	}
	for(int i=1;i<n;i++) {
		d[i]+=d[i-1];
		printf("%d ",d[i]);
	}
	puts("");
	return 0;
}