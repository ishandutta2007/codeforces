#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=4E5;
int read()
{
	int a=0;char b=1,c;
	do if((c=getchar())==45)b=-1;while(!(c&16));
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
	return a*b; 
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	char a[10],s=0;
	do a[s++]=x%10|48;while(x/=10);
	do putchar(a[--s]);while(s);
}

int main()
{
    for(int x=read();x--;)
    {
    	ll ma=0,sum=0,n=read()-1;
    	for(int i=n;i>=0;--i)
    	{
    		ll t=read();
    		ma=max(ma,t),sum+=t;
		}
		ma*=n;
		if(ma>sum)printf("%lld\n",ma-sum);
		else
		{
			ll t=sum/n;
			if(sum%n)++t;
			printf("%lld\n",t*n-sum);
		}
	}
}