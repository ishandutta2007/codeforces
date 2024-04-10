#include<cstdio>
#include<cstring>
typedef long long ll;
const int N=1E5;
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
ll pow(ll a,ll n)
{
	ll ans=1;
	for(;n;n>>=1,a*=a)if(n&1)ans*=a;
	return ans;
}
int k[N],l[N],r[N];
int main()
{
    for(int x=read();x--;)
    {
    	ll a,b,s=0;
    	memset(l,0,sizeof l),memset(r,0,sizeof r),scanf("%lld%lld",&a,&b);
    	ll ans=a,min=a;
    	if(a%b){printf("%lld\n",a);continue;}
    	for(int i=2;i*i<=b;++i)if(b%i==0)
    	{
    		k[++s]=i;
    		while(a%i==0)a/=i,++l[s];
    		while(b%i==0)b/=i,++r[s];
		}
		if(b!=1)
		{
			k[++s]=b,++r[s];
			while(a%b==0)a/=b,++l[s];
		}
		for(int i=1;i<=s;++i)
		{
			ll t=pow(k[i],l[i]-r[i]+1);
			if(t<min)min=t;
		}
		printf("%lld\n",ans/min);
	}
}