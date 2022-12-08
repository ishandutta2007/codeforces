#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int d[210],a[110][110];
int main() {
	int T,n,m;
	scanf("%d",&T);
	while(T--) {
		memset(d,0,sizeof(d));
		int FL=1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) {
				scanf("%d",a[i]+j);
				d[i+j]^=a[i][j];
			}
		for(int i=2;i<=n+m&&FL;i++)
			if(d[i])FL=0;
		puts(FL?"Jeel":"Ashish");
	}
	return 0;
}