#include<cstdio>
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
    	int n=read(),m=read()-1,s=0;
    	for(int l=read();--n;)
    	{
    		int r=read();
    		if(r!=l)++s;
    		l=r;
		}
		write(s?m?s%m?s/m+1:s/m:-1:1),putchar('\n');
	}
	return 0;
}