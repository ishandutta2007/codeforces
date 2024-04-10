#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int a[300005];
vector<int> v[300005];
pii dfs(int x){
	if(v[x].empty())
	return mp(1,1);
	int ans=0,sum=0;
	if(a[x]==1)
	ans=1e9;
	for(auto it:v[x]){
		pii p =dfs(it);
		sum+=p.y;
		if(a[x]==0)
		ans+=p.x-1;
		else
		ans=min(ans,p.y-p.x);
	}
	if(a[x]==0)
	ans++;
	else
	ans=sum-ans;
//	printf("%d %d %d\n",x,ans,sum);
	return mp(ans,sum);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i = 2;i<=n;i++){
		int x;
		scanf("%d",&x);
		v[x].pb(i);
	}
	printf("%d\n",dfs(1).x);
}