#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int x;
		if(r&1)	x=(r+1)/2;
		else	x=r/2+1;
		if(x<=l)	printf("%d\n",r%l);
		else	printf("%d\n",r%x);
	}
	return 0;
}