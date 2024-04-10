#include <cstdio>
#include <cstring>

int n;

void solve(){
	if(n%4==0){
		printf("%d\n",n/4);
	}else if(n%4==1){
		if(n<=5) puts("-1");
		else printf("%d\n",(n-9)/4+1);
	}else if(n%4==2){
		if(n<=2) puts("-1");
		else printf("%d\n",(n-2)/4);
	}else if(n%4==3){
		if(n<15) puts("-1");
		else printf("%d\n",(n-15)/4+2);
	}
}

int main(){
#ifdef DEBUG
	//freopen("A.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		solve();
	}
	return 0;
}