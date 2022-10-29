#include<bits/stdc++.h>
using namespace std;
const int N=200020;
int n,k,t[2]={};
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		++t[x%2];
	}
	if(n==k)
		puts(t[1]%2 ? "Stannis" : "Daenerys");
	else if(t[1]<=(n-k)/2 || (t[0]<=(n-k)/2 && k%2==0))
		puts("Daenerys");
	else
		if(t[0]<=(n-k+1)/2 && k%2)
			puts("Stannis");
		else
			puts((n-k)%2 ? "Stannis" : "Daenerys");
	return 0;
}