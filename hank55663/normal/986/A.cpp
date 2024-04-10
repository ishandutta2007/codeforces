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
#define last Last
using namespace std;
typedef long long LL;
int main(){
	int n,m,k,s;
	scanf("%d %d %d %d",&n,&m,&k,&s);
	vector<int> ans[100005];
	vector<int> a[105];
	for(int i=1;i<=n;i++){
		int b;
		scanf("%d",&b);
		a[b].pb(i);
	}
	vector<int> v[100005];
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i=1;i<=k;i++){
		queue<pii> q;
		int vis[100005];
		MEM(vis);
		for(auto it:a[i]){
			q.push(mp(it,0));
			vis[it]=1;
		}
		while(!q.empty()){
			
			pii p=q.front();
			q.pop();
			ans[p.x].pb(p.y);
			for(auto it:v[p.x]){
				if(!vis[it]){
					q.push(mp(it,p.y+1));
					vis[it]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		sort(ans[i].begin(),ans[i].end());
		int sum=0;
		for(int j=0;j<s;j++)
		sum+=ans[i][j];
		printf("%d ",sum);
	}
}