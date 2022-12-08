#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
const int N=1e5+10;
#define int long long
typedef pair<int,int> pii;
int a[N],p[N],t[N];
pii cov[N];
vector<pii>add[N];
struct node {
	int a,b,id;
	node(){}
	node(int A,int B,int ID) {
		a=A,b=B,id=ID;
	}
}mul[N];
int cmp1(const node &x,const node &y) {
	return (__int128)(x.a)*y.b>(__int128)(y.a)*x.b;
}
int cmp(int a,int b) {
	return t[a]<t[b];
}
signed main() {
	int k,n,m,cnt=0;
	int id,b;
	scanf("%lld%lld%lld",&k,&n,&m);
	for(int i=1;i<=k;i++)
		scanf("%lld",a+i);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld%lld",t+i,&id,&b);
		if(t[i]==1)cov[id]=max(cov[id],mp(b,i));
		if(t[i]==2)add[id].push_back(mp(b,i));
		if(t[i]==3)mul[++cnt]=node(b,1,i);
	}
	for(int i=1;i<=k;i++) {
		if(cov[i].fi>a[i])add[i].push_back(mp(cov[i].fi-a[i],cov[i].se));
		sort(add[i].rbegin(),add[i].rend());
		for(pii j:add[i]) {
			mul[++cnt]=node(a[i]+j.fi,a[i],j.se);
			a[i]+=j.fi;
		}
	}
	sort(mul+1,mul+cnt+1,cmp1);
	m=min(m,cnt);
	printf("%lld\n",m);
	for(int i=1;i<=m;i++)
		p[i]=mul[i].id;
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++)
		printf("%lld ",p[i]);
	return 0;
}