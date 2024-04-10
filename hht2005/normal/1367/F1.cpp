#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int a[maxn],p[maxn],q[maxn];
int cmp(int x,int y) {
	return a[x]==a[y]?x<y:a[x]<a[y];
}
int main() {
	int n,T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i),p[i]=i;
		sort(p+1,p+n+1,cmp);
		int ans=1,cnt=1;
		for(int i=2;i<=n;i++) {
			if(p[i]>p[i-1])cnt++;
			else cnt=1;
			ans=max(ans,cnt);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}