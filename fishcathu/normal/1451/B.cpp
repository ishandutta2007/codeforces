#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=1E5+10;
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
		int n=read(),m=read();
		scanf("%s",a+1);
		while(m--)
		{
			int l=read(),r=read(),k=0;
			for(int i=l;--i;)if(a[i]==a[l])k=1;
			for(int i=n;i>r;--i)if(a[i]==a[r])k=1;
			puts(k?"YES":"NO");
		}
	}
	return 0;
}