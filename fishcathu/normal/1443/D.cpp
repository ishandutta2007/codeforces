#include<cstdio>
#include<cstring> 
#include<algorithm>
const int N=3E5+10;
int read() 
{ 	
	int a; 
    scanf("%d",&a);
	return a; 
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
		int n=read();
		long long sum=0;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=2;i<=n;++i)if(a[i]<a[i-1])sum+=a[i-1]-a[i];
		puts(sum<=a[1]?"YES":"NO");
	} 
}