#include<bits/stdc++.h>
using namespace std;
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
void work(int l,int r,int n)
{
	for(int i=1,m=n>>1;i<=m;i<<=1)
	{
		int k=i<<1;
		for(int j=l;j<=r;j+=k)for(int z=0;z<i;++z)printf("%d %d\n",j+z,j+z+i);
	}
}
int main()
{
    int n=read(),k=0;
 	while(1<<k+1<=n)++k;
	if(1<<k==n)printf("%d\n",n/2*k),work(1,n,n);
	else printf("%d\n",(1<<k)*k),work(1,1<<k,1<<k),work(n-(1<<k)+1,n,1<<k);
}