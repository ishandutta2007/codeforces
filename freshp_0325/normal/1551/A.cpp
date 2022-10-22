#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int x;
		scanf("%d",&x);
		if(x%3==0)	printf("%d %d\n",x/3,x/3);
		else if(x%3==1)	printf("%d %d\n",x/3+1,x/3);
		else	printf("%d %d\n",x/3,x/3+1);
	}
	return 0;
}