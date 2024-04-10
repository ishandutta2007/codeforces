#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;
set<int> factor[200005];
int a[200005];
vector<int> v[200005];
int ans;
map<int,int> dfs(int x,int f){
	map<int,int> vv;
	for(auto it:v[x]){
		if(it!=f){
			map<int,int> vvv=dfs(it,x);
			for(auto it:vvv){
				if(factor[a[x]].find(it.x)!=factor[a[x]].end()){
					ans=max(vv[it.x]+it.y+1,ans);
					vv[it.x]=max(vv[it.x],it.y);
				}
			}
		}
	}
	for(auto it:factor[a[x]])
	vv[it],ans=max(ans,1);
	for(auto &it:vv)
	it.y++;
	return vv;
}
int main(){
	for(int i=2;i<200005;i++){
		if(factor[i].empty()){
			for(int j=i;j<200005;j+=i)
				factor[j].insert(i);
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	printf("%d\n",ans);
}