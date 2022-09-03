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
	int n;
	scanf("%d",&n);
	LL a[400005];
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	LL ans=0;
	for(int i = 3;i<=2*n;i++){
		a[i]+=a[i-2];
	}
	for(int i = n+1;i<=2*n;i++){
		ans=max(ans,a[i]-a[i-n-1]);
	//	printf("%lld\n",a[i]-a[i-n-1]);
	}
	printf("%lld\n",ans);
	return 0;
}