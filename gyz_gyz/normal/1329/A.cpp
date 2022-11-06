#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
int a[N];
int main(){ll n,tot=0;int m;
	scanf("%lld%d",&n,&m);
	rep(i,1,m){
		scanf("%d",&a[i]);
		tot+=a[i];
		if(i-1+a[i]>n)return printf("-1\n"),0;
	}
	if(tot<n)return printf("-1\n"),0;
	ll l=1;
	rep(i,1,m){
		ll nw=max(l,n-tot+1);
		printf("%lld%c",nw,i==n?'\n':' ');
		l=nw+1;tot-=a[i];
	}
}