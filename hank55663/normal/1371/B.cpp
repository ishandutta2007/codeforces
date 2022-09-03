#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		LL n,r;
		scanf("%lld %lld",&n,&r);
		LL Min=min(n-1,r);
		LL ans=(1+Min)*Min/2;
		if(n<=r)ans++;
		printf("%lld\n",ans);
	}
	return 0;
}