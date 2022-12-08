#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
const int maxn=2e6+10,mod=998244353;
int S[15][15],P[maxn],ans,Sum,k;
vector<pii>sid[maxn];
void dfs(int x,int sum) {
	if(x>k) {
		if(sum==Sum)ans++;
		return;
	}
	for(int i=1;i<=x;i++)
		dfs(x+1,(sum+S[x][i])%mod);
}
int main() {
	int n,m,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&a,&b,&c);
		sid[a].push_back(mp(c,b));
	}
	P[0]=1;
	for(int i=1;i<=n;i++) {
		P[i]=P[i-1]*97ll%mod;
		Sum=(Sum+P[i])%mod;
	}
	cerr<<Sum<<endl;
	for(int i=1;i<=n;i++) {
		sort(sid[i].begin(),sid[i].end());
		for(int j=0;j<sid[i].size();j++)
			S[sid[i].size()][j+1]=(S[sid[i].size()][j+1]+P[sid[i][j].second])%mod;
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}