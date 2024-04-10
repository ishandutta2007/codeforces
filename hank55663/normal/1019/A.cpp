#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> v[3005];
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
	}
	for(int i=1;i<=m;i++){
		sort(v[i].begin(),v[i].end());
	}
	LL ans=1e18;
	for(int i=0;i<n;i++){
		vector<int> hi;
		LL sum=0;
		int tot=v[1].size();
		for(int j=2;j<=m;j++){
			int k;
			for(k=0;k<(int)v[j].size()-i;k++){
				//printf("%d %d %d %d\n",k,j,v[j].size()-i,k<(int)v[j].size()-i);
				sum+=v[j][k];
				tot++;
			}
			for(;k<v[j].size();k++)
				hi.pb(v[j][k]);
		}
		//printf("?\n");
		sort(hi.begin(),hi.end());
		int need=i+1-tot;
		for(int j=0;j<need;j++){
			sum+=hi[j];
		}
		//printf("%d\n",sum);
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}