#include <bits/stdc++.h>

int n,d,a[1000];

int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);int ans=1e8;
	for(int l=1;l<=n;++l)
		for(int r=l;r<=n;++r)
			if (a[r]-a[l]<=d){ans=std::min(ans,n-(r-l+1));}
	printf("%d",ans);
	return 0;
}