#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#define MAXN 1000010
#define LL long long
using namespace std;

LL n;
LL a[MAXN],p[MAXN][2];
vector<int> g[MAXN];
map<LL,LL> V;
LL ans=0;
multiset<int> S;

namespace Fenwick{
	LL c[MAXN];

	void add(int x,LL v){
		while(x<=n){
			c[x]+=v;
			x+=x&(-x);
		}
	}

	LL sum(int x){
		LL res=0;
		while(x){
			res+=c[x];
			x-=x&(-x);
		}
		return res;
	}
}

void pre_gao(){
	static LL last[MAXN];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++)
			if(a[i]&(1<<j)) last[j]=i;
			else p[i][0]=max(p[i][0],last[j]);
		p[i][0]++;
	}
	for(int i=0;i<=30;i++) last[i]=n+1;
	for(int i=n;i>=1;i--){
		p[i][1]=n+1;
		for(int j=0;j<=30;j++)
			if(a[i]&(1<<j)) last[j]=i;
			else p[i][1]=min(p[i][1],last[j]);
		p[i][1]--;
		if(V.count(a[i]))
			p[i][1]=min(p[i][1],V[a[i]]-1);
		V[a[i]]=i;
		g[p[i][1]].push_back(p[i][0]);
	}
}

int main(){
#ifdef DEBUG
	freopen("D.in","r",stdin);
#endif
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	pre_gao();
	for(LL i=1;i<=n;i++)
		ans+=(i-p[i][0]+1)*(p[i][1]-i+1);
	ans=n*(n+1)/2-ans;
	printf("%lld\n",ans);
	return 0;
}