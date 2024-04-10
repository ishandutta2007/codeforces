#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		long long a,b;
		scanf("%lld %lld",&a,&b);
		if(b==1)	puts("NO");
		else
		{
			if(b==2)	printf("YES\n%lld %lld %lld\n",13*a,3*a,16*a);
			else	printf("YES\n%lld %lld %lld\n",a,a*(b-1),a*b);
		}
	}
	return 0;
}