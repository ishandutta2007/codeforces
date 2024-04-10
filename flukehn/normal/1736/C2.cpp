#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int a[N],n;
int b[20][N];
int g(int l,int r){
	int k=__lg(r-l+1);
	int ret= min(b[k][l],b[k][r-(1<<k)+1]);
	//dbg(l,r,ret);
	return ret;
}

int f[N], f2[N];
using pa=pair<int,ll>;
vector<pa> e[N];
ll ans[N];
int m;
struct P{
	int p,x,id;
} q[N];

vector<int> ed[N];

struct BIT{
	ll c[N];
	void clear(){
		for(int i=1;i<=n;++i) c[i]=0;
	}
	void add(int x,ll v){
		for(;x<=n;x+=x&-x)c[x]+=v;
	}
	ll qry(int x){
		ll r=0;
		for(;x;x-=x&-x)r+=c[x];
		return r;
	}
} t1,t2;
void solve(){
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i) b[0][i]=a[i]-i;
	for(int i=1;(1<<i)<=n;++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			b[i][j]=min(b[i-1][j],b[i-1][j+(1<<i-1)]);

	ll ans_pre=0;
	for(int i=1;i<=n;++i) {
		e[i].clear();
	}
	//e2.clear();
	for(int i=1;i<=n;++i){
		//if(a[i]<1-i) continue;
		
		int l=i,r=n;
		while(l<r){
			int m=(l+r+1)/2;
			if(g(i,m)>=1-i) l=m;
			else r=m-1;
		}
		ans_pre+=l-i+1;
		f[i]=l;
		f2[i]=l;
		if(l==n) {
		
		}else {
			++l;
			int L=l,R=n;
			while(L<R){
				int m=(L+R+1)/2;
				if(m==l || g(l+1,m) >= 1-i) L=m;
				else R=m-1;
			}
			f2[i]=L;
			int v=l+1-i, w=f2[i]-f[i];
			dbg(l,v,w);
			e[l].emplace_back(v,(ll)w);
		}
	}
	for(int i=1;i<=n;++i) {
		sort(e[i].begin(),e[i].end());
		For(j,1,e[i].size())
			e[i][j].second += e[i][j-1].second;
	}
	cin>>m;
	for(int i=1;i<=m;++i) {
		int p,x;
		cin>>p>>x;
		q[i]=(P){p,x,i};
	}
	sort(q+1,q+m+1,[](P a,P b){return a.p<b.p;});
	int now=1;
	//ll sum=0,tot=0;
	for(int i=1;i<=n;++i) ed[i].clear();
	t1.clear();
	t2.clear();
	for(int i=1;i<=m;++i) {
		auto [p,x,id]=q[i];
		if(a[p]==x){
			ans[id]=ans_pre;
		}else if(a[p]<x){
			auto v=lower_bound(e[p].begin(), e[p].end(), pa(x+1,-11451419));
			ll tmp=ans_pre;
			if(v!=e[p].begin()) {
				--v;
				tmp+=v->second;
			}
			ans[id]=tmp;
		}else{
			if(x-p >= 0){
				ans[id]=ans_pre;
				continue;
			}
			for(;now<=p;++now) {
				//sum+=f[now];
				//tot+=1;
				//int r=n+1-now;
				t1.add(now+1, f[now]);
				t2.add(now+1, 1);
				ed[f[now]].push_back(now);
				dbg(now, f[now]);
				for(int x:ed[now-1]) {
					//sum-=f[x],tot-=1;
					t1.add(x+1, -f[x]);
					t2.add(x+1, -1);
					dbg(x,f[x]);
				}
				
			}
			int v=x+n-p;
			ll sum=t1.qry(n-v+1);
			ll tot=t2.qry(n-v+1);
			dbg(v, sum,tot);
			ans[id]=ans_pre-sum+tot*(p-1);
		}
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<"\n";
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>n) solve();
}