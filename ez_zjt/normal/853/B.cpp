#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#define MAXN 1000010
#define LL long long
#define INF 0x77777777
using namespace std;

int n,m,k,maxd=1000000;
int g[MAXN];
LL f1[MAXN],f2[MAXN];
vector<pair<int,int> > g1[MAXN],g2[MAXN];

void gao1(){
	int cnt=n;
	LL res=0;
	memset(g,0x77,sizeof g);
	for(int i=1;i<=maxd;i++){
		for(int j=0;j<g1[i].size();j++){
			int x=g1[i][j].first,w=g1[i][j].second;
			if(g[x]==INF) cnt--;
			else res-=g[x];
			g[x]=min(g[x],w);
			res+=g[x];
		}
		if(!cnt) f1[i]=res;
		else f1[i]=1LL<<40;
	}
}

void gao2(){
	int cnt=n;
	LL res=0;
	memset(g,0x77,sizeof g);
	for(int i=maxd;i>=1;i--){
		for(int j=0;j<g2[i].size();j++){
			int x=g2[i][j].first,w=g2[i][j].second;
			if(g[x]==INF) cnt--;
			else res-=g[x];
			g[x]=min(g[x],w);
			res+=g[x];
		}
		if(!cnt) f2[i]=res;
		else f2[i]=1LL<<40;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int day,from,to,w;
		scanf("%d%d%d%d",&day,&from,&to,&w);
		if(!to) g1[day].push_back(make_pair(from,w));
		else g2[day].push_back(make_pair(to,w));
	}
	gao1();
	gao2();
	LL ans=1LL<<62;
	for(int i=2;i+k-1<maxd;i++){
		LL temp=f1[i-1]+f2[i+k];
		if(temp<ans) ans=temp;
	}
	if(ans>=(1LL<<40)) puts("-1");
	else printf("%lld\n",ans);
}