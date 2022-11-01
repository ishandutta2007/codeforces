#include<cstdio>
const int N=100000;
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
		int n=read(),t=read();
		n==1?n=0:n-=2;
		write(n%t?n/t+2:n/t+1),putchar('\n');
	}
}