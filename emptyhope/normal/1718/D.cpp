#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
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

#define maxn 500005 
#define inf 0x3f3f3f3f

int n,m,k,bad,p[maxn],a[maxn],b[maxn],rt;
set<int>s;
vector<pii>o;

int ch[maxn][2],nl,nr;
int st[maxn],tp;

int dfs(int u,int lst)
{
	if(a[u] && a[u]>lst)bad=1;
	int mx=a[u];
	if(ch[u][0]) mx=max(mx,dfs(ch[u][0],a[u]?a[u]:lst));
	if(ch[u][1]) mx=max(mx,dfs(ch[u][1],a[u]?a[u]:lst));
	if(!a[u]) o.pb(mkp(mx,lst));
	return mx;
}

bool cmp(pii a,pii b){
	return a.se<b.se;
}
void work()
{
	n=read(),m=read(),nl=nr=0,bad=tp=k=0; o.clear(); s.clear();
	For(i,1,n)p[i]=read(),ch[i][0]=ch[i][1]=0;
	For(i,1,n)a[i]=read(),k+=(!a[i]);
	For(i,1,k-1)b[i]=read(),s.insert(b[i]);
	For(i,1,n){
		while(tp&&p[st[tp]]<p[i])ch[i][0]=st[tp--];
		ch[st[tp]][1]=i,st[++tp]=i;
	}
	rt=st[1],dfs(rt,5000000);
	sort(o.begin(),o.end(),greater<pii>());
	for(auto t:o){
		int l=t.fi,r=t.se;
		auto it=s.upper_bound(r);
		if(it==s.begin() || (*prev(it))<l){
			if(nl) bad=1;
			nl=l;
		}
		else --it,s.erase(it);
	}
	s.clear(); For(i,1,k-1)s.insert(b[i]); 
	sort(o.begin(),o.end(),cmp);
	for(auto t:o){
		int l=t.fi,r=t.se;
		auto it=s.lower_bound(l);
		if(it==s.end()||(*it)>r){
			if(nr) bad=1;
			nr=r;
		}
		else s.erase(it);
	}
	if(bad){while(m--)read(),puts("No");return;}
	while(m--){
		int x=read();
		puts(x>=nl&&x<=nr?"Yes":"No");
	}
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}