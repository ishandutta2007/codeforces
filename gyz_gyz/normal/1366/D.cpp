#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=1e9+7;
const int mx=1e7;
default_random_engine e;
int ui(int l,int r){
	uniform_int_distribution<int>u(l,r);
	return u(e);
}
int tot,a[N],p[N],v[mx+1];
int q[N];pii ans[mx+1];
pii sol(int n){int tt=0,x=n;
	while(x>1){int cnt=0,p=v[x];
		while(v[x]==p)x/=p,++cnt;
		dep(i,tt,1){int r=1;
			rep(j,1,cnt){r*=p;
				if(r*a[i]!=n)a[++tt]=r*a[i];
			}
		}int r=1;
		rep(j,1,cnt){r*=p;
			if(r!=n)a[++tt]=r;
		}
	}
	rep(i,1,tt)rep(j,i+1,tt)if(__gcd(a[i]+a[j],n)==1)return {a[i],a[j]};
	return {-1,-1};
}
int main(){int n;e.seed(time(0));
	rep(i,2,mx){
		if(!v[i])p[++tot]=i,v[i]=i;
		rep(j,1,tot){
			if(i*p[j]>mx)break;
			v[i*p[j]]=p[j];
			if(!(i%p[j]))break;
		}
	}
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&q[i]);
		if(!ans[q[i]].fr)ans[q[i]]=sol(q[i]);
	}
	rep(i,1,n)printf("%d%c",ans[q[i]].fr,i==n?'\n':' ');
	rep(i,1,n)printf("%d%c",ans[q[i]].sc,i==n?'\n':' ');
}