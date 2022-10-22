#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) fot(int i=(s),_t=(t); i>=_t; --i)

inline void rd(int &x) {
	static char c;x=0;
	while(c=getchar(),c<48);
	do x=(x<<3)+(x<<1)+(c^48);
	while(c=getchar(),c>47);
}

typedef long long ll;

const int M=(int)2e5+500;

int Lt[M],Rt[M];
ll cost[M];
int main() {
	int n,h;
	rd(n);rd(h);
	FOR(i,1,n) {
		rd(Lt[i]);
		rd(Rt[i]);
	}
	FOR(i,1,n) cost[i]=cost[i-1]+Lt[i]-Rt[i-1];
	ll res=0;
	FOR(i,1,n) {
		int r=upper_bound(cost+i,cost+n+1,cost[i]+h-1)-cost-1;
		if(1ll*Rt[r]-Lt[i]+h-(cost[r]-cost[i])>res) res=1ll*Rt[r]-Lt[i]+h-(cost[r]-cost[i]);
	}
	printf("%lld\n",res);
	return 0;
}