#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3E5;
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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
char a[N];
int vis[N],ans;
int b[N][2];
const int p=998244353;
int pow(int x)
{
	int res=1;
	for(int i=2;x;x>>=1)
	{
		if(x&1)res=res*1LL*i%p;
		i=i*1LL*i%p;
	}
	return res;
}
void solve(int u,int v,bool k)
{
	if(a[u]=='*')return;
	b[u][k]=b[u][k]*1LL*pow(vis[v]-vis[u]-1)%p;
	ans=(ans+b[u][k])%p;
	b[v][k]=(b[v][k]-b[u][k])%p;
}
int main()
{
	int n=read(),m=read(),s=n*m;
	for(int i=0;i<s;i+=m)scanf("%s",a+i);
	for(int i=0,cnt=0,val=1;i<s;++i)
	{
		if(a[i]=='*')continue;
		ans=ans*2%p;
		vis[i]=++cnt;
		b[i][0]=b[i][1]=val;
		if(i%m)solve(i-1,i,0);
		if(i>=m)solve(i-m,i,1);
		val=val*2%p;
	}
	write((ans+p)%p,'\n');
}