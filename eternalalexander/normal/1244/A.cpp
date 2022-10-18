#include <bits/stdc++.h>

int main(){
	int t,a,b,c,d,k;scanf("%d",&t);
	while (t--){
		int flag=0;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		for(int i=1;i<=k;++i){
			if (c*i>=a){
				if (d*(k-i)>=b){
					printf("%d %d\n",i,k-i);flag=1;}
				break;
			}
		}if (flag==0)printf("-1\n");
	}
	return 0;
}