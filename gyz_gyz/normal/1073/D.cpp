#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
int n,x,nt[N];ll ans,m,tot,a[N];
int main(){
	scanf("%d%lld",&n,&m);
	rep(i,1,n){
		scanf("%lld",&a[i]);tot+=a[i];
	}
	rep(i,1,n-1)nt[i]=i+1;nt[n]=1;x=n;
	while(n){
		ans+=m/tot*n;m%=tot;
		for(;a[nt[x]]<=m;m-=a[x])x=nt[x],ans++;
		n--;tot-=a[nt[x]];nt[x]=nt[nt[x]];
	}
	printf("%lld\n",ans);
}