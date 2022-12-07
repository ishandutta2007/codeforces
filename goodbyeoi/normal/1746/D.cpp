#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,k,s[M];
vector<int>e[M];
map<pii,int>t;

int dfs(int u,int k)
{
	if (t.find(mp(u,k))!=t.end())return t[mp(u,k)];
	int deg=e[u].size();
	if (deg==0)return t[mp(u,k)]=s[u]*k;
	int res=s[u]*k;
	int x1=k/deg,x2=x1+1,c1=deg-k%deg,c2=k%deg;
	vector<int>v;
	for (auto x:e[u])
	{
		int s1=dfs(x,x1);
		if (c2)
		{
			int s2=dfs(x,x2);
			v.pb(s2-s1);
		}
		res+=s1;
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for (int i=0;i<c2;i++)res+=v[i];
	return t[mp(u,k)]=res;
}

void solve()
{
	n=read(),k=read();t.clear();
	for (int i=1;i<=n;i++)e[i].clear();
	for (int i=2;i<=n;i++)e[read()].pb(i);
	for (int i=1;i<=n;i++)s[i]=read();
	cout<<dfs(1,k)<<'\n';
}

signed main()
{
	WT solve();
	return 0;
}