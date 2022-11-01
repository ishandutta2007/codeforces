#include<cstdio>
#include<cstring> 
const int N=5001;
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
int dp1[N],dp2[N];char a[N],b[N];
int main()
{
    int n=read(),m=read(),ans=0;
    scanf("%s%s",a+1,b+1);
    for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
	    {
	    	if(a[i]==b[j])dp2[j]=dp1[j-1]+2;
	    	else
	    	{
		    	dp2[j]=dp2[j-1]>dp1[j]?dp2[j-1]:dp1[j];
		    	dp2[j]=dp2[j]>0?dp2[j]-1:0;
		    }
			if(dp2[j]>ans)ans=dp2[j];
		}
		memcpy(dp1,dp2,sizeof dp1);
	}
	write(ans);
}