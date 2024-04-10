#include <bits/stdc++.h>
int n,t,a[10000],b[10000];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	std::sort(a+1,a+n+1);std::sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)printf("%d ",a[i]);printf("\n");
	for(int i=1;i<=n;++i)printf("%d ",b[i]);printf("\n");
}

int main(){
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}