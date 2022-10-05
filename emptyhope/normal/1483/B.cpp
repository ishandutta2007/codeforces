#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
#define maxn 300005
#define inf 0x3f3f3f3f3f3f3f3f

int n,nxt[maxn],pre[maxn],a[maxn];
vector<int>o;
bool vis[maxn];
void del(int x)
{
	o.pb(x); vis[x]=1;
	pre[nxt[x]]=pre[x];
	nxt[pre[x]]=nxt[x];
	pre[x]=nxt[x]=0;
}
queue<pii>q;
void work()
{
	o.clear();
	while(!q.empty()) q.pop();
	n=read();
	For(i,0,n+1)pre[i]=nxt[i]=0;
	For(i,1,n)a[i]=read(),vis[i]=0;
	For(i,1,n){
		int ai=a[i],aj=(i==n?a[1]:a[i+1]);
		pre[i]=(i==1?n:i-1);
		nxt[i]=(i==n?1:i+1);
		if(__gcd(ai,aj)==1) q.push(mkp(i,nxt[i]));
	}
	while(!q.empty())
	{
		pii t=q.front(); q.pop();
		if(vis[t.fi]||vis[t.se]) continue;
	//	cout<<"fi se "<<t.fi<<' '<<t.se<<endl;
		del(t.se);
		{
			int ai=a[t.fi],aj=a[nxt[t.fi]];
	//		cout<<"ai aj "<<ai<<' '<<aj<<endl;
			if(__gcd(ai,aj)==1) q.push(mkp(t.fi,nxt[t.fi]));
		}
	}cout<<o.size()<<' ';
	for(auto x:o)cout<<x <<' ';puts("");
}

signed main()
{
	int T=read();
	while(T--)work();
    return 0;
}