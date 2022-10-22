#include<bits/stdc++.h>
#define Sunset namespace
#define Toybox std
using Sunset Toybox;
int main(){
	int n,s;
	scanf("%d %d",&n,&s);
	if(s<2*n)	return puts("NO")&0;
	else
	{
		puts("YES");
		printf("%d ",s-2*n+2);
		s-=s-2*n+2;
		for(int i=1;i<n;++i)	printf("2 ");
		puts("");
		printf("1");
	}
	return 0;
}