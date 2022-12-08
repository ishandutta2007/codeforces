#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e6;

int n, l, r, ql, qr, w[sz], lsum[sz], rsum[sz];
int main()
{
	scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
	rep(i,0,n)
		scanf("%d",&w[i]);
	lsum[0] = w[0];
	rep(i,1,n)
		lsum[i] = w[i]+lsum[i-1];
	rsum[n-1]=w[n-1];
	for(int i=n-2;i>=0;i--)
		rsum[i] = w[i]+rsum[i+1];
	int best = INT_MAX;
	rep(i,-1,n)
	{
		int cost=0;
		if(i>=0)
			cost+=l*lsum[i];
		if(i+1<n)
			cost+=r*rsum[i+1];
		int ltake = i+1;
		int rtake = n-ltake;
		if(ltake>rtake)
			cost+=ql*(ltake-rtake-1);
		else if(rtake>ltake)
			cost+=qr*(rtake-ltake-1);
		if(cost<best)
			best = cost;
	}
	printf("%d\n",best);
}