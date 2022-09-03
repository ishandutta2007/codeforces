#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		int a[200005];
		for(int i = 0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		int w[200005];
		int cnt=0;
		for(int i = 0;i<k;i++){scanf("%d",&w[i]);if(w[i]==1)cnt++;}
		sort(w,w+k);
		reverse(w,w+k);
		LL ans=0;
		for(int i = n-1;i>=n-k;i--)ans+=a[i];
		for(int i = n-1;i>=n-cnt;i--)ans+=a[i];
		int now=0;
		for(int i = 0;i<k;i++){
			if(w[i]==1)break;
		//	printf("%d %d\n",i,now);
			ans+=a[now];
			now+=max(w[i]-1,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}