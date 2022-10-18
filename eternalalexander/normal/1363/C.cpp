#include <bits/stdc++.h>
int d[1005],n,x;

void solve(){
	std::memset(d,0,sizeof(d));
	scanf("%d%d",&n,&x);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		d[u]++;d[v]++;
	}if(d[x]==1 || d[x] == 0)puts("Ayush");
	else {
		if ( ( n - 1 ) % 2 ) puts("Ayush");
		else puts("Ashish");
	}
}

int main(){
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}