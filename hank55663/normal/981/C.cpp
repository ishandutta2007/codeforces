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
vector<int> v[100005];
int dfs(int a,int f){
	if(v[a].size()>2)
	return -1;
	int ret=a;
	for(auto it:v[a]){
		if(it!=f){
			ret=dfs(it,a);
		}
	}
	return ret;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);	
	}
	int Maxi=0;
	for(int i=1;i<=n;i++){
		if(v[Maxi].size()<v[i].size()){
			Maxi=i;
		}
	}
	vector<int> vv;
	for(auto it:v[Maxi]){
		int x=dfs(it,Maxi);
		if(x==-1){
			printf("No\n");
			return 0;
		}
		vv.pb(x);
	}
	printf("Yes\n");
	printf("%d\n",vv.size());
	for(auto it:vv)
	printf("%d %d\n",it,Maxi);
}