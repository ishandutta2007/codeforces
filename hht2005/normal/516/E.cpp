#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pii;
const int N=4e5+10;
int n,m,A,B,c[N],t[N];
ll x,y,dis[N];
vector<int>a[N],b[N];
vector<pii>S[N];
map<int,int>in;
priority_queue<pii>q;
void exgcd(int a,int b,ll &x,ll &y) {
	if(b==0) {
		x=1,b=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y=y-a/b*x;
}
int cmp(int a,int b) {
	return (1ll*x*a)%n<(1ll*x*b)%n;
}
ll get(int x) {
	for(int i=1;i<=x;i++) {
		// for(pii j:S[i])
		// 	cerr<<i<<' '<<j.fi<<' '<<j.se<<endl;
		dis[i]=1e18;
	}
	dis[x]=0;
	q.push(make_pair(0,x));
	ll ans=0;
	while(!q.empty()) {
		pii t=q.top();
		q.pop();
		int x=t.se;
		ll v=t.fi;
		// cerr<<x<<' '<<v<<endl;
		if(dis[x]<v)continue;
		ans=max(ans,v);
		for(pii y:S[x])
			if(dis[y.fi]>v+y.se) {
				// cerr<<y.fi<<endl;
				dis[y.fi]=v+y.se;
				q.push(make_pair(dis[y.fi],y.fi));
			}
	}
	return ans;
}
ll solve(vector<int> a,vector<int> b) {
	int cnt=0;
	in.clear();
	for(int i:a)in[c[++cnt]=i]=1;
	for(int i:b)in[c[++cnt]=i]=1;
	sort(c+1,c+cnt+1);
	cnt=unique(c+1,c+cnt+1)-c-1;
	if(n==cnt) {
		for(int i:a)t[i]++;
		for(int i:b)t[i]++;
		int to=-1;
		for(int i=0;i<m;i++)
			if(t[i]==1)to=i;
		for(int i:a)t[i]--;
		for(int i:b)t[i]--;
		return to;
	}
	for(int i=1;i<=cnt;i++)
		c[i+cnt]=(c[i]-m+n)%n;
	cnt*=2;
	sort(c+1,c+cnt+1,cmp);
	cnt=unique(c+1,c+cnt+1)-c-1;
	// cerr<<cnt<<endl;
	for(int i=1;i<=cnt+1;i++)S[i].clear();
	for(int i=1;i<=cnt;i++) {
		if(in[c[i]])S[cnt+1].push_back(make_pair(i,c[i]));
		if(i<cnt)S[i].push_back(make_pair(i+1,((c[i+1]*x-c[i]*x)%n+n)%n*m));
	}
	S[cnt].push_back(make_pair(1,((c[1]*x-c[cnt]*x)%n+n)%n*m));
	// return 0;
	return get(cnt+1);
}
int main() {
	scanf("%d%d",&n,&m);
	int d=__gcd(n,m),X;
	n/=d,m/=d;
	if(d>2e5)return puts("-1"),0;
	scanf("%d",&A);
	for(int i=0;i<A;i++) {
		scanf("%d",&X);
		a[X%d].push_back(X/d);
	}
	scanf("%d",&B);
	for(int i=0;i<B;i++) {
		scanf("%d",&X);
		a[X%d].push_back(X/d);
	}
	if(d>A+B)return puts("-1"),0;
	if(n<m) {
		swap(n,m);
		for(int i=0;i<d;i++)
			swap(a[i],b[i]);
	}
	exgcd(m,n,x,y);
	ll ans=0;
	x=(x+n)%n;
	for(int i=0;i<d;i++) {
		if(!a[i].size()&&!b[i].size())return puts("-1"),0;
		ans=max(ans,solve(a[i],b[i])*d+i);
	}
	printf("%lld\n",ans);
	return 0;
}