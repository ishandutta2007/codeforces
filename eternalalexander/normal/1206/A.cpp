#include <bits/stdc++.h>

int ma=0,mb=0,n,m,t;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){scanf("%d",&t);ma=std::max(ma,t);}
	scanf("%d",&m);
	for (int i=1;i<=m;++i){scanf("%d",&t);mb=std::max(mb,t);}
	printf("%d %d",ma,mb);
	
	return 0;
}