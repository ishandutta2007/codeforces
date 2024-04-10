#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		k=(n>k)?((n-1)/k+1)*k:k;
		int ans=ceil(double(k)/double(n));
		printf("%d\n",ans);
	}
	return 0;
}