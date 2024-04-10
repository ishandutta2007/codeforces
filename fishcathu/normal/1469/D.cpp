#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E6+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int a[7];
void f(int l,int r)
{
	write(l);
	putchar(' ');
	write(r);
	putchar('\n');
}
int main()
{
	a[1]=2;
	for(int i=2;i<=5;++i)a[i]=a[i-1]*a[i-1];
	for(int x=read();x--;)
	{
		int n=read(),s=2;
		while(s<=5&&a[s]<n)++s;
		write(n-3+s);
		putchar('\n');
		for(int i=3,j=2;i<n;++i)
		{
			if(i==a[j])++j;
			else f(i,n);
		}
		--s;
		f(n,a[s]);
		f(n,a[s]);
		while(s>=2)
		{
			f(a[s],a[s-1]);
			f(a[s],a[s-1]);
			--s;
		}
	}
}