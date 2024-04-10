#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
pii p[5005];
vector<int> v[5005];
int vis[5005];
int ans;
bool check(int a,int b){
	vis[a]=1;
	if(v[a].size()<ans){
		v[a].pb(b);
		return true;
	}
	for(vector<int>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(!vis[*it]&&check(*it,a)){
			*it=b;
			return true;
		}
	}
	return false;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	ans=0;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		MEM(vis);
		if(check(x,y))continue;
		MEM(vis);
		if(check(y,x))continue;
		ans++;
		v[y].pb(x);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++){
			printf("%d %d\n",i,*it);
		}
	}
}