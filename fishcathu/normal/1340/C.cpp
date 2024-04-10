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
const int N=1E4+1;
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
int a[N],y,now;
int vis[N][1001];
struct st
{
	int w,k,val;
	st(int b,int c,int d)
	{
		w=b;
		k=c;
		val=d;
	}
};
deque<st>q;
void ins(int x,int k,int val)
{
	if(k>y||vis[x][k])return;
	if(val==now)q.push_front(st(x,k,val));
	else q.push_back(st(x,k,val));
}
int main()
{
    read();
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    sort(a+1,a+1+n);
    for(int i=n;i>=2;--i)a[i]-=a[i-1];
    y=read();
	int z=read()+y; 
    ins(1,y,0);
    while(!q.empty())
    {
    	st x=q.front();
    	q.pop_front();
    	int w=x.w,k=x.k,val=x.val;
    	if(vis[w][k])continue;
    	vis[w][k]=val;
    	now=val;
    	if(k==y)
    	{
    		k=0;
    		++val;
		}
		if(w!=1)ins(w-1,k+a[w],val);
		if(w!=n)ins(w+1,k+a[w+1],val);
	}
	int ans=1<<30;
	for(int i=1;i<=y;++i)
	{
		if(vis[n][i])
		{
			ans=min(ans,vis[n][i]*z+i);
		}
	}
	if(ans==1<<30)puts("-1");
	else write(ans-z,'\n');
}