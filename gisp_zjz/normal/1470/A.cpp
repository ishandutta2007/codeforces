#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
int _,n,m,b[maxn];
ll a[maxn];

int main(){
	scanf("%d",&_);
	while (_--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		for (int i=1;i<=m;i++) scanf("%lld",&a[i]);
		ll ans=0;
		sort(b+1,b+n+1);
        for (int i=1;i<=n;i++) ans+=a[min(b[i],n+1-i)];
        printf("%lld\n",ans);
	}
	return 0;
}