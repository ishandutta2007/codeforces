#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T;
int main(){
	T=read();
	while(T--)
	{
		int a,b,c,d;
		a=read();
		b=read();
		c=read();
		d=read();
		if(a==c&&b==d)
		{
			puts("0");
			continue;
		}
		if(a==c)
		{
			printf("%d\n",abs(b-d));
			continue;
		}
		if(b==d)
		{
			printf("%d\n",abs(a-c));
			continue;
		}
		printf("%d\n",abs(a-c)+abs(b-d)+2);
	}
	return 0;
}