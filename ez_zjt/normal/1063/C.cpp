#include <bits/stdc++.h>

int n;
int s0;

bool getres(){
	char str[10];
	scanf("%s",str);
	return str[0]=='b';
}

int main(){
	scanf("%d",&n);
	int l=0,r=1000000000;
	puts("1 0");
	fflush(stdout);
	s0=getres();
	for(int i=2;i<=n;i++){
		int mid=(l+r)>>1;
		printf("1 %d\n",mid);
		fflush(stdout);
		int s=getres()^s0;
		if(s) r=mid;
		else l=mid;
	}
	if(l+2<=r){
		printf("%d %d %d %d\n",0,l+1,2,l+1);
	}else{
		printf("%d %d %d %d\n",0,l,2,l+1);
	}
}