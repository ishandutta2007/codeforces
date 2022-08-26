#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+100;
int _,n,a[maxn],b[maxn],cnt[maxn],c[maxn],x,y,q;

int main(){
	for (int i=1;i<maxn;i++) a[i]=1;
	for (int i=2;i*i<maxn;i++)
		for (int j=1;j*i*i<maxn;j++)
			a[j*i*i]=i*i;
	for (int i=1;i<maxn;i++){
		b[i]=i;
		while (a[b[i]]>1) b[i]/=a[b[i]];
	}
	scanf("%d",&_);
	while (_--){
		scanf("%d",&n); x=0; y=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&c[i]);
			c[i]=b[c[i]];
			cnt[c[i]]++;
			x=max(x,cnt[c[i]]);
		}
		y=x;
		for (int i=1;i<=n;i++){
			if (!cnt[c[i]]) continue;
			if (c[i]==1) continue;
			if (cnt[c[i]]%2) continue;
			cnt[1]+=cnt[c[i]]; cnt[c[i]]=0;
			y=max(y,cnt[1]);
		}
		scanf("%d",&q);
		while (q--){
			long long t;scanf("%lld",&t);
			printf("%d\n",!t?x:y);
		}
		for (int i=1;i<=n;i++) cnt[c[i]]=0; cnt[1]=0;
	}
}