#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second

int ask(ll x){
	printf("? %lld\n",x);
	fflush(stdout);
	int y;scanf("%d",&y);
	return y;
}

ll calc(ll n){
	if(n==1)return 1;
	return (n+1)/2+1-calc((n+1)/2);
}
void solve(ll n){
	ll pos=calc(n);
	ll l=1,r=n,u=1;
	ask(pos);
	while(l<r){
		ll mid=(l+r-1)>>1;pos+=mid*u;
		if(ask(pos))r=mid;
		else l=mid+1;
		u*=-1;
	}
	printf("= %lld\n",r);
	fflush(stdout);
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int T;scanf("%d",&T);ll n;
	while(T--){
		scanf("%lld",&n);
		solve(n);
	}
	return 0;
}