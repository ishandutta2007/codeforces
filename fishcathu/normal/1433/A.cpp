#include<cstdio>
const int N=200001;
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
		int t=read(),s=t%10,m=1;
		while(t/=10)++m;
		printf("%d\n",10*(s-1)+(m+1)*m/2);
	} 
}