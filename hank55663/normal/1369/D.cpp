#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int mod=1e9+7;
LL ans[2000005][2];
int main() {
	ans[1][1]=ans[1][0]=0;
	ans[2][0]=ans[2][1]=0;
	for(int i = 3;i<=2000000;i++){
		ans[i][1]=(ans[i-1][0]+ans[i-2][0]*2+1)%mod;
		ans[i][0]=(max(ans[i-1][0],ans[i-1][1])+max(ans[i-2][0],ans[i-2][1])*2)%mod;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
	//	printf("%lld %lld\n",ans[x][0],ans[x][1]);
		printf("%lld\n",max(ans[x][0],ans[x][1])*4%mod);
	}
	return 0;
}