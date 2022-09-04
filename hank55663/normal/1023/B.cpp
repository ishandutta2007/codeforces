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
#define index Index
using namespace std;
typedef long long LL;
int main(){
	LL n,k;
	scanf("%lld %lld",&n,&k);
	LL ans;
	if(k-1<=n){
		ans=k/2;
		//printf("%lld\n",k/2);
	}
	else{
		ans=max(0ll,(n-(k-n)+2)/2);
		//printf("%lld\n",max(0ll,(n-(k-n))/2+1));
	}
	if(k%2==0&&k/2<=n){
		ans--;
	}
	printf("%lld\n",ans);
}