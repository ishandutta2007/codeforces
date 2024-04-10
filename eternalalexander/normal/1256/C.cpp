#include <bits/stdc++.h>
int n,m,d,c[10005],s[100005],v[10005];
int main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;++i)scanf("%d",&c[i]);
	int p=0,i=1;
	while (i<=m){
		s[i]=p+d;
		p=p+d+c[i]-1;
	//	printf("%d %d\n",i,p);
		i++;
	}if (p+d<=n){printf("NO");return 0;}
	s[m+1]=n+1;
	for(int i=m;i>=1;i--){s[i]=std::min(s[i],s[i+1]-c[i]);}
	printf("YES\n");
	for(int i=1;i<=m;++i)
		for(int j=s[i];j<=s[i]+c[i]-1;++j)v[j]=i;
	for(int i=1;i<=n;++i)printf("%d ",v[i]);
	return 0;
}