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
int a[200005];
vector<int> v[200005];
bool cmp(const int &x,const int &y){
	return a[x]<a[y];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	int seq[200005];
	for(int i=0;i<n;i++){
		scanf("%d",&seq[i]);
		a[seq[i]]=i;
	}
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end(),cmp);
	}
	int vis[200005];
	MEM(vis);
	vector<int> bfs;
	queue<int> q;
	q.push(1);
	vis[1]=1;
	bfs.pb(1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto it:v[x]){
			if(!vis[it]){
				q.push(it);
				bfs.pb(it);
				vis[it]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(seq[i]!=bfs[i]){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}