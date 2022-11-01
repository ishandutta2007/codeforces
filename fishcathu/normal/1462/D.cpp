#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3010;
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
int a[N],n;
int check(int x)
{
	int ans=0;
	for(int i=1,s=0;i<=n;++i)
	{
		s+=a[i];
		if(s>x)return -1;
		if(s==x)s=0,++ans;
	}
	return n-ans;
}
int main()
{
	for(int x=read();x--;)
	{
		n=read();
		int s=0;
		for(int i=1;i<=n;++i)s+=a[i]=read();
		int k=1;
		while(k*k<=s&&(s%k||!~check(k)))++k;
		if(k*k<=s)
		{
			write(check(k));
			putchar('\n');
			continue;
		}
		while(s%--k||!~check(s/k));
		write(check(s/k));
		putchar('\n');
	}
}