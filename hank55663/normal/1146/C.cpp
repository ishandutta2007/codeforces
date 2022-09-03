/*#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;*/
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
#define ld long double
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i = 0;(1<<i)<=n;i++){
			vector<int> v1,v2;
			for(int j=1;j<=n;j++){
				if(j&(1<<i)){
					v1.pb(j);
				}
				else{
					v2.pb(j);
				}
			}
			printf("%d %d",v1.size(),v2.size());
			for(auto it:v1)
			printf(" %d",it);
			for(auto it:v2)
			printf(" %d",it);
			printf("\n");
			fflush(stdout);
			int x;
			scanf("%d",&x);
			ans=max(ans,x);
		}
		printf("-1 %d\n",ans);
		fflush(stdout);
	}
	return 0;
}