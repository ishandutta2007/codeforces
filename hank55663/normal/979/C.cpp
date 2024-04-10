#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
vector<int> ans;
vector<int> v[300005];
int dfs(int x,int f,int target){
	int sum=1;
	for(auto it:v[x]){
		if(it!=f){
			sum+=dfs(it,x,target);
		}
	}
	if(target==x)
	ans.pb(sum);
	return sum;
}
int main(){
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
	for(int i =1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(x,0,y);
	dfs(y,0,x);
	printf("%lld\n",(LL)n*(n-1)-(LL)ans[0]*ans[1]);
}