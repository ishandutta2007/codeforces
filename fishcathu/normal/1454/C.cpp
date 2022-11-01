#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=2E5+1;
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
int a[N];bool b[N];
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),l=read(),ans=n;
		for(int i=1;i<=n;++i)a[i]=b[i]=0;
		b[l]=1;
		for(int i=n;--i;)
		{
			int t=read();
			if(l!=t)++a[t];
			b[l=t]=1;
		}
		--a[l];
		for(int i=1;i<=n;++i)if(b[i]&&a[i]<ans)ans=a[i];
		printf("%d\n",ans+1);
	}
}