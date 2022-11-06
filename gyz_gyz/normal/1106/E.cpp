#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 100010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,k,d[N],t[N];ll w[N],f[N][210];pii l[N],r[N];
struct pt{int x;};
bool operator <(pt x,pt y){
	return w[x.x]==w[y.x]?d[x.x]==d[y.x]?x.x<y.x:d[x.x]>d[y.x]:w[x.x]>w[y.x];
}set<pt>s;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k){
		scanf("%d%d%d%lld",&l[i].fr,&r[i].fr,&d[i],&w[i]);
		l[i].sc=r[i].sc=i;
	}
	sort(l+1,l+k+1);sort(r+1,r+k+1);int t1=1,t2=1;
	rep(i,1,n){
		for(;t1<=k&&l[t1].fr<=i;++t1)s.insert({l[t1].sc});
		for(;t2<=k&&r[t2].fr<i;++t2)s.erase({r[t2].sc});
		t[i]=s.empty()?0:s.begin()->x;
	}
	rep(i,1,n+1)rep(j,0,m)f[i][j]=Inf;
	f[1][0]=0;ll ans=Inf;
	rep(i,1,n){
		int tt=(t[i]?d[t[i]]:i)+1;
		rep(j,0,m){
			if(j<m)f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
			f[tt][j]=min(f[tt][j],f[i][j]+w[t[i]]);
		}
	}
	rep(i,0,m)ans=min(ans,f[n+1][i]);
	printf("%lld\n",ans);
}