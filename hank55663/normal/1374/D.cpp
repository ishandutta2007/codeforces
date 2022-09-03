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
map<LL,LL> m;
int k;
LL Find(LL x){
	if(m.find(x)==m.end()||m[x]==x)return m[x]=x;
	else 
	return m[x]=Find(m[x]);
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d %d",&n,&k);
		m.clear();
		LL ans=0;
		for(int i = 0;i<n;i++){
			int a;
			scanf("%d",&a);
			if(a%k==0)continue;
			ans=max(ans,Find(k-a%k));
		//	printf("%lld\n",Find(k-a%k));
			m[Find(k-a%k)]=Find(k-a%k)+k;
		}
		if(ans==0)
		printf("0\n");
		else
		printf("%lld\n",ans+1);
	}
	return 0;
}