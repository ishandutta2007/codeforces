#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
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
using namespace std;
typedef long long LL;
	int vis[300005];
		int a[300005];
int main(){
	int n;
	scanf("%d",&n);
	int back=n;

	MEM(vis);

	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int ans=1;
	printf("1");
	for(int i=1;i<=n;i++){
		vis[a[i]]=1;
		ans++;
		while(vis[back]==1){
			back--;
			ans--;
		}
		printf(" %d",ans);
	}
	return 0;
}