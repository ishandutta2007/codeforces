#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> v[200005];
int val[200005];
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		fill(val,val+n+1,0);
		for(int i = 1;i<=n;i++)v[i].clear();
		for(int  i = 0;i<m;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			v[x].pb(y);
		}
		vector<int> ans;

		for(int i = 1;i<=n;i++){
			if(val[i]==2)ans.pb(i);
			else{
				for(auto it:v[i]){
					val[it]=max(val[it],val[i]+1);
				}
			}	
		}
		printf("%d\n",ans.size());
		assert(ans.size()<=n*4/7);
		for(auto it:ans){
			printf("%d ",it);
		}
		printf("\n");
	}
	return 0;
}