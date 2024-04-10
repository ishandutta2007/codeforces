#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",n/10+(n%10==9));
	}
	return 0;
}