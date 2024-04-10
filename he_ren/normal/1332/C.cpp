#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

char s[MAXN];

int fa[MAXN];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i]=i;}
int find(int u){ return u==fa[u]? u: fa[u]=find(fa[u]);}
void connect(int u,int v){ fa[find(u)]=find(v);}

int cnt[MAXN][26+5];

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	init(n);
	for(int i=1; i+d<=n; ++i)
		connect(i,i+d);
	for(int i=1; i<=(n>>1); ++i)
		connect(i,n-i+1);
	
	for(int i=1; i<=n; ++i)
		for(int j=0; j<26; ++j)
			cnt[i][j]=0;
	
	for(int i=1; i<=n; ++i)
		++cnt[find(i)][s[i]-'a'];
	
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		if(find(i)!=i) continue;
		
		int tot=0,mx=0;
		for(int j=0; j<26; ++j)
			tot += cnt[i][j],
			chk_max(mx,cnt[i][j]);
		ans += tot-mx;
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}