#include<cstdio>
#include<cstring>
const int N=3E5+1;
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
int a[N],l[N];
int main()
{
    for(int x=read();x--;)
    {
    	memset(a,0,sizeof a),memset(l,0,sizeof l);
    	int n=read(),r=n;
    	for(int i=1;i<=n;++i)
    	{
    		int t=read();
    		if(i-l[t]>a[t])a[t]=i-l[t];
    		l[t]=i;
		}
		for(int i=1;i<=n;++i)if(n+1-l[i]>a[i])a[i]=n+1-l[i];
		for(int i=1;i<=n;++i)if(a[i]<=r)
		{
			for(int j=a[i];j<=r;++j)l[j]=i;
			r=a[i]-1;	
		} 
		for(int i=r;i--;)printf("-1 ");
		for(int i=r+1;i<=n;++i)write(l[i]),putchar(i==n?'\n':' ');
	}
	return 0;
}