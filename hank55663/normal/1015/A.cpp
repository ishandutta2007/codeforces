#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	int ans[105];
	MEM(ans);
	int n,m;
	scanf("%d %d ",&n,&m);
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		for(int j=l;j<=r;j++)
			ans[j]=1;
	}
	vector<int> v;
	for(int i=1;i<=m;i++)
		if(!ans[i])
			v.pb(i);
	printf("%d\n",v.size());
	for(auto it:v)
	printf("%d ",it);
}