#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int id[maxn],a[maxn];
int cmp(int x,int y) {
	return a[x]>a[y];
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),id[i]=i;
	sort(id+1,id+1+n,cmp);
	int sum=0;
	for(int i=1;i<=n;i++)sum+=a[id[i]]*(i-1)+1;
	printf("%d\n",sum);
	for(int i=1;i<=n;i++)
		printf("%d ",id[i]);
	return 0;
}