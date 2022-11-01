#include<cstdio>
#include<cstring>
typedef long long ll;
const int N=1E5+1;
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
    	int a=read(),b=read(),c=read(),d=read(),e=(a%b?a/b:a/b-1)/d*d,f=e/d+1;
    	if(a>b*1ll*c){puts("-1");continue;}
    	printf("%lld\n",f*1ll*a-(e*1ll*b*f>>1));
	}
	return 0;
}