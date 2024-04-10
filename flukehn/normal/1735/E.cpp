#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1011;
struct E{
	int w, x,y;
} eg[N*N*2];
int n;
int a[N],b[N];
vector<int> e[N];
int lk[N], to[N];
int vis[N];
int dfs(int x){
	if(vis[x]) return 0;
	vis[x]=1;
	for(int y:e[x]) {
		if(!lk[y] || dfs(lk[y])) {
			lk[y]=x;
			to[x]=y;
			return 1;
		}
	}
	return 0;
}
int work(int w,int l,int r){
	for(int i=1;i<=n;++i) e[i].clear();
	for(int i=l;i<r;++i) {
		int x=eg[i].x;
		int y=eg[i].y;
		e[x].push_back(y);
	}
	for(int i=1;i<=n;++i)lk[i]=0;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) vis[j]=0;
		if(!dfs(i)) return 0;
	}
	cout<<"YES\n";
	//for(int i=1;i<=n;++i) dbg(to[i], a[i], b[to[i]]);
	for(int i=1;i<=n;++i) {
		int j=to[i];
		if(a[i] - b[j] == w) {
			// hi - a = hj - b	

		} else if(a[i] + b[j] == w) {
			b[j] = -b[j];
		} else if(-a[i] + b[j] == w) {
			a[i] = -a[i];
			b[j] = -b[j];
		} else {
			a[i] = -a[i];
		}
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	//debug("a: ");for(int i=1;i<=n;++i) debug(a[i]<<" \n"[i==n]);
	//debug("b: ");for(int i=1;i<=n;++i) debug(b[i]<<" \n"[i==n]);
	for(int i=2;i<=n;++i)assert(a[i]-a[i-1]==b[i]-b[i-1]);
	int f=0;
	if(a[1]<b[1]) {
		swap(a,b);
		f=1;
	}
	w=a[1]-b[1];
	int d1=0,d2;
	if(a[1]<0) {
		d1-=a[1];
		for(int i=2;i<=n;++i) a[i]-=a[1];
		a[1]=0;
	}
	d2=d1+w;
	if(f)swap(d1,d2);
	for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
	cout<<d1<<" "<<d2<<'\n';
	return 1;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	int tot=0;
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=n;++j) {
			int x=abs(a[i]-b[j]);
			int y=abs(a[i]+b[j]);
			//e[x].push_back((E){i,j});
			eg[tot++]=(E){x,i,j};	
			if(x!=y)eg[tot++]=(E){y,i,j};	
		}
	sort(eg,eg+tot,[](const E&a,const E&b){
		return a.w<b.w;
	});
	for(int i=0,j;i<tot;i=j){
		for(j=i;j<tot&&eg[j].w==eg[i].w;++j);
		if(j-i>=n && work(eg[i].w,i,j)) return;
	}
	cout<<"NO\n";
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}	
}