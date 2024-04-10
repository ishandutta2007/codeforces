#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
vector<int>S[N];
int w[N],p[N];
map<int,map<int,int> >f;
signed main() {
	int T,n,m,a,b;
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld%lld",&n,&m);
		f.clear();
		for(int i=1;i<=n;i++) {
			S[i].clear();
			scanf("%lld",w+i);
		}
		for(int i=1;i<=m;i++) {
			scanf("%lld%lld",&a,&b);
			if(f[a][b])continue;
			f[a][b]=1;
			S[b].push_back(a);
		}
		for(int i=1;i<=n;i++) {
			sort(S[i].begin(),S[i].end());
			S[i].push_back(i);
		}
		sort(S+1,S+n+1);
		int cnt=0,las=0;
		for(int i=1;i<=n;i++) {
			if(S[i].size()==1)continue;
			int t=w[*--S[i].end()];
			S[i].pop_back();
			if(las&&S[i]==S[las])p[cnt]+=t;
			else p[++cnt]=t;
			las=i;
		}
		int g=0;
		for(int i=1;i<=cnt;i++)
			g=__gcd(g,p[i]);
		printf("%lld\n",g);
	}
	return 0;
}