#include<bits/stdc++.h>
using namespace std;
const int N=110;
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
int a[N];
int main()
{
	int n=read(),m=0;
	for(int i=n;i--;)m^=read();
	if(!m||n%2)
	{
		puts("YES");
		if(n%2==0)--n;
		printf("%d\n",n-2);
		for(int i=1;i<=n-2;i+=2)printf("%d %d %d\n",i,i+1,i+2);
		for(int i=1;i<n-2;i+=2)printf("%d %d %d\n",i,i+1,n);
	}
	else puts("NO");
}