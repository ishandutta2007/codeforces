#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		if(k>=n)	printf("%d",k-n);
		else	printf("%d",((k&1)==(n&1))?0:1);
		puts("");
	}
	return 0;
}