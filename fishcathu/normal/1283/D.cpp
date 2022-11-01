#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N],b[N];
set<int>vis;
queue<pii>q;
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		vis.insert(a[i]);
		q.push({a[i],-1});
		q.push({a[i],1});
	}
	ll sum=0;
	for(int s=0;s<m;)
	{
		pii x=q.front();
		q.pop();
		int k=x.se,w=x.fi+k;
		if(vis.count(w))continue;
		vis.insert(w);
		b[++s]=w;
		if(k>0)
		{
			sum+=k;
			q.push({x.fi,k+1});
		}
		else
		{
			sum-=k;
			q.push({x.fi,k-1});
		}
	}
	write(sum,'\n');
	for(int i=1;i<=m;++i)write(b[i],' ');
}