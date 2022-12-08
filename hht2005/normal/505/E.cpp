#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
typedef pair<int,int> pii;
#define fi first
#define se second
int c[N],a[N],h[N],n,m,k,p;
priority_queue<pii,vector<pii>,greater<pii> >q;
int check(int H) {
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++) {
		c[i]=0;
		if(H-m*a[i]<h[i])
			q.push(make_pair(H/a[i],i));
	}
	for(int i=1;i<=m&&!q.empty();i++) {
		for(int j=1;j<=k&&!q.empty();j++) {
			pii t=q.top();
			q.pop();
			int x=t.se;
			if(t.fi<i)return 0;
			c[x]++;
			if(H+c[x]*p-m*a[x]<h[x]) {
				q.push(make_pair((H+c[x]*p)/a[x],x));
			}
		}
	}
	return q.empty();
}
signed main() {
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",h+i,a+i);
	int l=1,r=1e18;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",r+1);
	return 0;
}