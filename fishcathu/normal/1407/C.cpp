#include<bits/stdc++.h>
using namespace std;
const int N=1E4+10;
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
    int n=read(),mx=1;
    for(int i=2;i<=n;++i)
	{
		printf("? %d %d\n",i,mx),cout.flush();
		int l=read();
		printf("? %d %d\n",mx,i),cout.flush();
		int r=read();
		if(l<r)a[mx]=r,mx=i;
		else a[i]=l;
	} 
	a[mx]=n;
	putchar('!');
	for(int i=1;i<=n;++i)printf(" %d",a[i]);
	return 0;
}