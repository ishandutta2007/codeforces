#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int mo=998244353;
ll l[111],r[111],s[111],sz[111],a[111][111];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll cal(int n,ll m){
	ll res=1;
	rep(i,1,n)res=res*(n+m-i)%mo*qk(i,mo-2)%mo;
	return res;
}
int main(){int n;ll sz=1;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld%lld",&l[i],&r[i]);
		s[i*2-1]=l[i];s[i*2]=++r[i];
		sz=sz*(r[i]-l[i])%mo;
	}
	sort(s+1,s+n*2+1);
	int tot=unique(s+1,s+n*2+1)-(s+1);
	rep(i,1,n){
		l[i]=lower_bound(s+1,s+tot+1,l[i])-s;
		r[i]=lower_bound(s+1,s+tot+1,r[i])-s;
	}
	rep(i,1,tot+1)a[0][i]=1;
	rep(i,1,n){
		rep(j,l[i],r[i]-1)dep(k,i-1,0){
			a[i][j]=(a[i][j]+a[k][j+1]*cal(i-k,s[j+1]-s[j]))%mo;
			if(l[k]>j||r[k]<=j)break;
		}
		dep(j,tot,1)a[i][j]=(a[i][j]+a[i][j+1])%mo;
	}
	printf("%lld\n",a[n][1]*qk(sz,mo-2)%mo);
}