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
#define index Index
#define N 300005
using namespace std;
typedef long long LL;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		int x[1005];
		for(int i=0;i<k;i++)
		scanf("%d",&x[i]);
		int ans=0;
		for(int i=1;i<=n;i++){
			int res=1e9;
			for(int j=0;j<k;j++){
				res=min(res,abs(x[j]-i)+1);
			}
		//	printf("%d\n",res);
			ans=max(ans,res);
		}
		printf("%d\n",ans);
	}
	
}