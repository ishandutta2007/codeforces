#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 6;
const int MAXD = 1e6 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int a[MAXN];
struct Node
{
	int x,id;
}b[MAXN];
inline bool cmp(const Node &p,const Node &q){ return p.x<q.x;}

struct Number
{
	int x,cnt,ecnt;
}c[MAXN];

vector<int> f[MAXD];

int main(void)
{
	int n,d;
	ll l;
	cin>>n>>l>>d;
	int nn=l%n;
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) b[i] = (Node){a[i],i};
	sort(b+1,b+n+1,cmp);
	int m=0;
	for(int i=1,j=1; j<=n; i=j)
	{
		c[++m].x = b[i].x;
		while(j<=n && b[j].x==b[i].x)
		{
			if(b[j].id <= nn) ++c[m].ecnt;
			++j;
		}
		c[m].cnt = j-i;
	}
	
	for(int i=0; i<=d; ++i)
		f[i].resize(m+5);
	for(int i=1; i<=m; ++i) f[0][i]=1;
	
	int ans=0;
	for(int i=1; i<=d; ++i)
	{
		for(int j=1; j<=m; ++j)
			f[i][j] = (ll)f[i-1][j] * c[j].cnt %mod;
		for(int j=1; j<=m; ++j)
			add_mod(f[i][j], f[i][j-1]);
		
		if(i-1 > l/n) continue;
		add_mod(ans, (ll)(l/n-i+1) %mod * f[i][m] %mod);
		for(int j=1; j<=m; ++j)
			add_mod(ans, (ll)f[i-1][j] * c[j].ecnt %mod);
	}
	
	printf("%d",ans);
	return 0;
}