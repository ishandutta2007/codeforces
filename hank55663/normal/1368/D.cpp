#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int cnt[21];
	MEM(cnt);
	for(int i = 1;i<=n;i++ ){
		int x;
		scanf("%d",&x);
		for(int j=0;j<20;j++){
			if(x&(1<<j))cnt[j]++;
		}
	}
	LL ans=0;
	for(int i = 1;i<=n;i++){
		LL val=0;
		for(int j =0;j<20;j++){
			if(cnt[j]){
				cnt[j]--;
				val+=(1<<j);
			}
		}
		ans+=val*val;
	}
	printf("%lld\n",ans);
	return 0;
}