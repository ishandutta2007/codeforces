#include<cstdio>
#include<cstring>
const int N=100001;
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
bool p(int x)
{
	if(x==1)return 0;
	int i=2;
	while(i*i<=x&&x%i)++i;
	return i*i>x;
}
int main()
{
	
	for(int x=read();x--;)
	{
		int n=read(),t=1;
		while(p(t)||!p(t+n-1))++t;
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)write(i==j?t:1),putchar(j==n?'\n':' ');
	}
}