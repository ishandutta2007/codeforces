#include<cstdio>
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
int t[N],x[N],y[N],mx[N],ans[N];
int main()
{
	int n=read(),s=0;
	for(int m=read();m--;)
	{
		t[s]=read(),x[s]=read(),y[s]=read();
		if(x[s]+y[s]<=t[s]+2)
		{
			ans[s]=1;
			int ma=(x[s]<<1>n+1?x[s]-1:n-x[s])+(y[s]<<1>n+1?y[s]-1:n-y[s]),j;
			for(j=s;j--&&t[s]-t[j]<ma;)if(ans[j]>=ans[s]&&t[s]-t[j]>=(x[s]>x[j]?x[s]-x[j]:x[j]-x[s])+(y[s]>y[j]?y[s]-y[j]:y[j]-y[s]))ans[s]=ans[j]+1;
			if(~j&&mx[j]>=ans[s])ans[s]=mx[j]+1;
			mx[s]=mx[s-1]>ans[s]?mx[s-1]:ans[s];
			++s;
		}
	}
	write(mx[s-1]);
	return 0;
}