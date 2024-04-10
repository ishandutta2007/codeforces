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
const int N=1<<20;
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
int a[N<<1];
bitset<N>b;
int ans[N],cnt;
bool check(int i)
{
	while(1)
	{
		int t=a[ls]>a[rs]?ls:rs;
		if(!a[t])break;
		i=t;
	}
	return b[i];
}
void del(int i)
{
	ans[++cnt]=i;
	while(1)
	{
		int t=a[ls]>a[rs]?ls:rs;
		if(!a[t])break;
		a[i]=a[t];
		i=t;
	}
	a[i]=0;
}
void work(int i)
{
	if(!a[i])return;
	while(check(i))del(i);
	work(ls);
	work(rs);
}
void solve()
{
	int n=(1<<read())-1,m=(1<<read())-1;
	for(int i=1;i<=m;++i)b[i]=0;
	for(int i=m+1;i<=n;++i)b[i]=1;
	for(int i=1;i<=n;++i)a[i]=read();
	cnt=0;
	work(1);
	ll sum=0;
	for(int i=1;i<=m;++i)sum+=a[i];
	write(sum,'\n');
	for(int i=1;i<=cnt;++i)write(ans[i],' ');
	putchar('\n');
	memset(a+1,0,n<<2);
}
int main()
{
    for(int x=read();x--;)
    {
    	solve();
	}
}