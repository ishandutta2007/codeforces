#include<cstdio>
#include<algorithm>
const int N=60;
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
int a[N],b[N]; 
int main()
{
    for(int x=read();x--;)
    {
    	int n=read(),m=read();
    	for(int i=0;i<n;++i)a[i]=read();
    	for(int i=0;i<n;++i)b[i]=read();
    	std::sort(a,a+n),std::sort(b,b+n);
    	int i=0;
    	while(i<n&&a[i]+b[n-1-i]<=m)++i;
    	puts(i<n?"No":"Yes");
	}
}