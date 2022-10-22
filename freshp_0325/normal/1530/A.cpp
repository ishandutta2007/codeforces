#include<bits/stdc++.h>
using namespace std;
int main(){
	int T
	;scanf("%d",&T);
	while(T-->0)
	{
		int n;
		scanf("%d",&n);
		int p=0;
		while(n)	p=max(p,n%10),n/=10;
		printf("%d\n",p);
	}
	return 0;
}