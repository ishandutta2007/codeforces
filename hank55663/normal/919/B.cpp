#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
#define N 200005
using namespace std;
typedef long long LL;
vector<int> ans;
void dfs(int sum,int dep,int need){
	if(need<0)
	return;
	if(dep == 1){
		ans.pb(sum+need);
		return;
	}
	for(int i=0;i<9;i++){
		dfs((sum+i)*10,dep-1,need-i); 
	}
	if(sum%10==0)
	dfs((sum+9)*10,dep-1,need-9);
} 
int main(){
	for(int i=2;ans.size()<10000;i++){
		dfs(1,i,9);
	}	
	sort(ans.begin(),ans.end());
	int k;
	scanf("%d",&k);
	printf("%d\n",ans[k-1]);
}