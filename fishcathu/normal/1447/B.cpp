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
int a[N];
int main()
{
    for(int x=read();x--;)
    {
    	int n=read(),m=read(),sum=0,s=0,mi=N;
    	for(int i=0;i<n;++i)for(int j=0;j<m;++j)
    	{
    		int t=i*n+j;
    		a[t]=read();
    		if(a[t]<0)++s,a[t]=-a[t];
			sum+=a[t];
    		if(a[t]<mi)mi=a[t];
		}
		printf("%d\n",s%2?sum-2*mi:sum);
	}
}