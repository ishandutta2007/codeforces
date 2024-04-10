#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
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
int l[N],r[N],ans[N];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		l[i]=read();
		r[i]=read();
		ans[i]=i;
	}
	for(int i=1;i<n;++i)
	{
		ll mx=0;
		int res;
		for(int j=i+1;j<=n;++j)
		{
			int u=l[ans[j]]-l[ans[i]];
			int v=r[ans[j]]-r[ans[i]];
			ll w=u*1ll*u+v*1ll*v;
			if(w>mx)
			{
				mx=w;
				res=j;
			}
		}
		swap(ans[i+1],ans[res]);
	}
	for(int i=1;i<=n;++i)write(ans[i],' ');
}