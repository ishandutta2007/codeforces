#include <bits/stdc++.h>
int n,u,v,d[100005];
double s;
int main(){
	scanf("%d%lf",&n,&s);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		d[u]++;d[v]++;
	}int cnt=0;
	for(int i=1;i<=n;++i)cnt+=(d[i]==1);
	printf("%.10f",(s/cnt)*2);
	return 0;
}