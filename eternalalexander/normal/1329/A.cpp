#include <bits/stdc++.h>
int n,m,l[100005],p[100005];
long long sum;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d",&l[i]);
		sum+=l[i];
		if(n-l[i]<i-1){puts("-1");return 0;}
		p[i]=i;
	}if(sum<n){puts("-1");return 0;}
	p[m+1]=n+1;
	for(int i=m;i>=1;i--)
		if(p[i]+l[i]<p[i+1])
			p[i]=p[i+1]-l[i];
	for(int i=1;i<=m;++i)printf("%d ",p[i]);
	return 0;
}