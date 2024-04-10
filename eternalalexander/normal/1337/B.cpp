#include <bits/stdc++.h>

int x,n,m,t;

void solve(){
	scanf("%d%d%d",&x,&n,&m);
	while (x>0&&n&&x/2+10<x){n--;x=x/2+10;}
	if (x<=m*10)printf("YES\n");
	else printf("NO\n"); 
}

int main(){
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}