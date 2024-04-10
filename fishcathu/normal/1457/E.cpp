#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
priority_queue<ll>q;int a[N];
int main()
{
    int n=read(),k=read();
    for(int i=1;i<=n;++i)a[i]=read();
    sort(a+1,a+1+n,greater<int>());
    for(int i=0;i<=k;++i)q.push(0);
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
    	ll t=q.top();
    	ans+=t,q.pop();
    	q.push(t+a[i]);
	}
	printf("%lld",ans);
}