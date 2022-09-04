#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pli pair<LL,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
using namespace std;
typedef long long LL;
vector<int> v[200005];
int depth[200005];
void dfs(int a,int dep,int f){
	depth[a]=dep;
	for(vector<int>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(*it!=f)
		dfs(*it,dep+1,a);
	} 
}
int ans=0;
void dfs2(int a,int f,int sum){
	ans=max(depth[a],ans);
	for(vector<int>::iterator it=v[a].begin();it!=v[a].end();it++){
		if(*it!=f){
			if(sum+1<depth[*it])
			dfs2(*it,a,sum+1); 
		}
	}
}
int visit[200005];
int main(){	
	int n,x;
	scanf("%d %d",&n,&x);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,0,0);
	dfs2(x,0,0);
	printf("%d\n",ans*2);
}