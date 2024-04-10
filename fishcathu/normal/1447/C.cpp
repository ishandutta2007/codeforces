#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1E6;
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
pair<ll,int>a[N];
int main()
{
    for(int x=read();x--;)
    {
    	int n=read();
    	ll m,sum=0;
    	scanf("%lld",&m);
    	ll mm=(m+1)>>1;
    	for(int i=1;i<=n;++i)a[i].first=read(),a[i].second=i;
    	sort(a+1,a+1+n);
    	int t=lower_bound(a+1,a+1+n,make_pair(mm,0))-a;
    	if(t<=n&&a[t].first<=m){printf("1\n%d\n",a[t].second);continue;}
    	int i=t;
    	while(sum<mm&&i>1)sum+=a[--i].first;
    	if(sum<mm){puts("-1");continue;}
    	printf("%d\n",t-i);
    	for(int j=t-1;j>=i;--j)printf("%d%c",a[j].second,j==i?'\n':' ');
	}
}