#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5E5+10;
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
pii a[N];
set<int>q;
int w[N<<1],fa[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].fi=read();
		a[i].se=read();
		fa[i]=i;
	}
	sort(a+1,a+1+n);
	int s=n-1;
	for(int i=1;i<=n;++i)
	{
		set<int>::iterator it=q.upper_bound(a[i].fi);
		while(it!=q.end())
		{
			int t=*it;
			if(t>a[i].se)break;
			int u=find(i),v=find(w[t]);
			if(u==v)
			{
				puts("NO");
				return 0;
			}
			fa[u]=v;
			--s;
			++it;
		}
		q.insert(a[i].se);
		w[a[i].se]=i;
	}
	puts(s?"NO":"YES");
}