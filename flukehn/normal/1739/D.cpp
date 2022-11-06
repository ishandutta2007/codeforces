#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=2e5+11;
int p[N];
vector<int> e[N];
int n,K;
int tot, rb;
int dfs(int x){
	int f=0;
	for(int y:e[x]) {
		int r=dfs(y);
		if(x>1 && r==rb) {
			//r=0;
			tot+=1;
		}else {
			f=max(f,r);
		}
	}
	return f+1;
}
int calc(int m) {
	if(m==1) return n-1-e[1].size();
	tot=0;
	rb=m;
	dfs(1);
	return tot;
}
void solve(){
	cin>>n>>K;
	for(int i=2;i<=n;++i) cin>>p[i];
	
	for(int i=1;i<=n;++i) e[i].clear();
	for(int i=2;i<=n;++i) e[p[i]].push_back(i);
	
	int l=1,r=n-1;
	while(l<r){
		int m=(l+r)>>1;
		if(calc(m) <= K) r=m;
		else l=m+1;
	}
	cout<<l<<"\n";
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