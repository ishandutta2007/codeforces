#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		LL ans=0;
		LL a[200005];
		for(int i = 0;i<n;i++){
			scanf("%lld",&a[i]);
			if(i&1);
			else ans+=a[i];
		}
		LL Min=0,now=0;
		LL res=0;
		a[n]=0;
		for(int i = 0;i<n-1;i+=2){
			now=now+a[i+1]-a[i];
			Min=min(Min,now);
			res=max(res,now-Min);
		}
		Min=0,now=0;
		for(int i = 1;i<n-1;i+=2){
			now=now-a[i+1]+a[i];
			Min=min(Min,now);
			res=max(res,now-Min);
		}
		printf("%lld\n",res+ans);
	}
	return 0;
}