#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL T;
	scanf("%lld",&T);
	while(T-->0)
	{
		LL n,a,b;
		scanf("%lld %lld %lld",&n,&a,&b);
		if(a==1)
		{
			puts(n%b==1 || b==1?"Yes":"No");
			continue;
		}
		LL pos=1;
		bool flag=false;
		while(pos<=n)
		{
			if((n-pos)%b==0)
			{
				puts("Yes");
				flag=true;
				break;
			}
			pos*=a;
		}
		if(!flag)	puts("No");
	}
	return 0;
}

/*
a^{x_1}(a^{x_2}(...)+y2b)+y1b

x_n = 0
y_n = 0
*/