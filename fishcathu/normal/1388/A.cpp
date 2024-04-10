#include<bits/stdc++.h>
using namespace std;
const int N=1E6;
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
    	int n=read();
    	if(n<=30)puts("NO");
		else 
		{
			puts("YES");
			int t=n==36||n==40||n==44?15:14;
			printf("6 10 %d %d\n",t,n-16-t); 
		}
	}
}