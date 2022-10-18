#include <bits/stdc++.h>
int n;
int main(){
	scanf("%d",&n);n*=2;
	if (n/2%2!=1)printf("NO");
	else {
		printf("YES\n");
		for (int i=1;i<=n;++i){
			if (i%2==0)printf("%d ",(i>n/2?i-n/2:i)*2-1);
			else printf("%d ",(i>n/2?i-n/2:i)*2);
		}
	}
	return 0;
}