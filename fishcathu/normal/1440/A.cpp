#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=2E5+5;
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
char a[N];
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),b=read(),c=read(),d=read(),l=0,r=0;
		scanf("%s",a);
		for(int i=0;i<n;++i)++(a[i]=='0'?l:r);
		c=min(c,b+d),b=min(b,c+d);
		printf("%d\n",b*l+c*r);
	} 
}