#include <cstdio>
#include <cstring>
#define LL long long

int main(){
	LL n,k;
	scanf("%I64d%I64d",&n,&k);
	LL n2=n%(k+k);
	if(n2>=k)
		puts("YES");
	else
		puts("NO");
}