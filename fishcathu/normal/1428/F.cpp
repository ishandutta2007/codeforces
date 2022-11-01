#include<cstdio>
typedef long long ll;
const int N=5E5+10;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    while(c!=10)c=getchar();
    return a*b; 
} 
void write(int x) 
{
    if(x<0)putchar('-'),x=-x; 
    char a[10],s=0; 
    do a[s++]=x%10|48;while(x/=10); 
    do putchar(a[--s]);while(s);
}
int a[N>>1],b[N>>1],last[N]; 
int main()
{
	int n=read(),s=0;
	ll ans=0,sum=0;
	for(int i=1,k=1;i<=n;++i)
	{
		if(getchar()==48)k=1;
		else k?a[++s]=i,k=0,b[s]=1:++b[s];
	}
	for(int i=1;i<=s;++i)
	{
		ans+=sum*(a[i]-last[1]-1);
		for(int j=1;j<=b[i];++j)ans+=sum+=(a[i]-last[j]-1);
		ll c=0;
		for(int j=1;j<=b[i];++j)last[j]=a[i]+b[i]-j,ans+=c+=j;
		sum+=c;
	}
	printf("%lld",ans+sum*(n-a[s]-b[s]+1));
	return 0;
}