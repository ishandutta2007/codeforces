#include<bits/stdc++.h>
using namespace std;
const int N=110;
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
int a[3][100]; 
int main()
{
    for(int x=read();x--;)
    {
    	int n=read();
    	for(int i=0;i<3;++i)for(int j=0;j<n;++j)a[i][j]=read();
    	for(int i=1;i<n;++i)
    	{
    		int j=0;
    		while(a[j][i]==a[0][i-1])++j;
    		a[0][i]=a[j][i];
		}
		int j=0;
		while(a[j][0]==a[0][1]||a[j][0]==a[0][n-1])++j;
		a[0][0]=a[j][0];
		for(int i=0;i<n;++i)printf("%d%c",a[0][i],i==n-1?'\n':' ');
	}
}