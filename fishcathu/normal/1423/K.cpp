#include<cstdio>
#include<cmath>
#include<algorithm>
const int N=2000000;
using namespace std;
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
bool b[N+1];int p[N];
int main()
{
	int t=0;
    for(int i=2;i<=N;++i)
    {
    	if(!b[i])p[++t]=i;
    	for(int j=1;j<=t&&i*p[j]<=N;++j)
    	{
    		b[i*p[j]]=1;
    		if(!i%p[j])break;
		}
	}
    for(int n=read();n--;)
    {
    	int m=read();
    	int l=upper_bound(p+1,p+t+1,sqrt(m))-p,r=upper_bound(p+1,p+t+1,m)-p;
    	write(r-l+1),putchar('\n');
	}
}