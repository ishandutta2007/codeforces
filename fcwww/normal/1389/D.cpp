#include<bits/stdc++.h>
using namespace std;
#define N 200050
typedef long long ll;
int n,K,l1,r1,l2,r2,b0,b1;
ll getj(int l1,int r1,int l2,int r2) {
	if(l1>l2) swap(l1,l2),swap(r1,r2);
	if(r1>=r2) return r2-l2;
	return max(0,r1-l2);
}
inline int Abs(int x) {return x>0?x:-x;}
int getb1(int l1,int r1,int l2,int r2) {
	l2=min(l2,r1);
	return l2-l1 + Abs(r2-r1);
}
void solve() {
	scanf("%d%d%d%d%d%d",&n,&K,&l1,&r1,&l2,&r2);
	ll ans=0;
	ll nj=getj(l1,r1,l2,r2);
	if(nj*n>=K) {puts("0");return ;}
	if(l1==l2&&r1==r2) {printf("%lld\n",(K-nj*n)<<1); return ;}
	if(l1>l2) swap(l1,l2),swap(r1,r2);
	b0=max(0,l2-r1);
	b1=getb1(l1,r1,l2,r2);
	K-=nj*n;
	int i;
	ans+=b0;
	ans+=min(b1,K);
	K-=min(b1,K);
	for(i=2;i<=n && K;i++) {
		int t=min(b1,K);
		if(b0+t>=2*t) {
			ans+=(K<<1); K=0;
		}else {
			ans+=b0+t; K-=t;
		}
	}
	if(K) ans+=(K<<1);
	printf("%lld\n",ans);
}
int main() {
	int cas;
	scanf("%d",&cas);
	while(cas--) solve();
}