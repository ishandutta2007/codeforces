#include<cstdio>
#include<cstring>
const int N=510;
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
int a[N][N],b[300000];
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)for(int j=1,k;j<=m;++j)a[i][j]=k=read(),b[k]=i;
		for(int i=1;i<m;++i)for(int j=1;j<=n;++j)read();
		for(int i=1;i<=n;++i)
		{
			int t=read();
			for(int j=1;j<=m;++j){int s=a[i][j];a[i][j]=a[b[t]][j],b[a[b[t]][j]=s]=b[t];}	
		} 
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)write(a[i][j]),putchar(j==m?'\n':' ');
	}
}