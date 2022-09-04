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
	vector<int> ans;
	int vis[105];
	MEM(vis);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(!vis[a]){
			vis[a]=1;
			ans.pb(i+1);
		}
	}
	if(ans.size()>=k){
		printf("YES\n");
		for(int i=0;i<k;i++)
		printf("%d ",ans[i]);
	}
	else printf("NO\n");
}