#include<cstdio>
main(){
	int n,k;
	scanf("%d %d",&n,&k);
	if(k>n){
		puts("-1");
	}else if(k==1){
		puts(n==1?"a":"-1");
	}else{
		char next='a';
		for(int i=0;i<n-(k-2);i++){
			printf("%c",next);
			next=next=='a'?'b':'a';
		}
		next='c';
		for(int i=n-(k-2);i<n;i++){
			printf("%c",next);
			++next;
		}
		puts("");
	}
}