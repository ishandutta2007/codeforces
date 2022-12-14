#include <cstdio>
#include <cstring>
#define MAXN 1000010
#define LL long long

int n=0,k;
char str[MAXN];

int main(){
	scanf("%d",&k);
	if(!k){
		puts("a");
		return 0;
	}
	for(int i=0;i<26;i++){
		if(!k) break;
		LL j;
		for(j=2;j*(j-1)/2<=k;j++);
		j--;
		k-=j*(j-1)/2;
		while(j--)
			str[++n]='a'+i;
	}
	for(int i=1;i<=n;i++)
		putchar(str[i]);
	puts("");
}