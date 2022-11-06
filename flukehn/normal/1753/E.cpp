#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=1e6+11,M=41;
int n,B,W1,W2,C;
char b[N];
int a[N];
//int p[M], q[M], tot;
//vector<int> pos[M];
int sz;
vector<int> c[M];
vector<ll> sc[M];
int tr[N], tc[M], ck[M];
ll ret;
int used[M];
using L=long long;
pair<int,L> calc(int i,ll mid){
	int s=c[i].size();
	if(!c[i].size() || 1LL * ck[i]* c[i][0] < mid) return pair<int,L>(0, (L)0);
	if(1LL*c[i][s-1] * ck[i]>= mid) {
		return pair<int,L>(s, (L)sc[i][s-1] * ck[i]);
	}
	int l=0,r=c[i].size()-1;
	while(l<r) {
		int m=(l+r+1)/2;
		if(1LL*ck[i]*c[i][m] >= mid) l=m;
		else r=m-1;
	}
	return pair<int,L>(l+1, (L)sc[i][l] * ck[i]);
}
void dfs(int i=sz){
	if(i==0){
		int tot_used=0;
		for(int j=1;j<=sz;++j) tot_used += used[j];
		for(int j=1;j<=sz;++j) {
			ck[j]=1;
			for(int k=1;k<=j;++k) if(used[k]) ck[j] *= a[tc[k]];
			for(int k=j+1;k<=sz;++k) ck[j] *= a[tc[k]];
		}
		if(1LL*tot_used * W2 > B) return;
		ll tmp=0;
		
		for(int j=1;j<=sz;++j) tmp+=ck[j] * sc[j].back();
		ret=max(ret,tmp);
		for(int j=1;j<=sz;++j) ck[j]=C-ck[j];
		
		
		ll l=0,r=4.1e18;
		
		dbg(tot_used, tmp, W1, W2, B);
		for(int j=1;j<=sz;++j) debug(ck[j]<<" \n"[j==sz]);
		auto work=[&](ll mid){
			int tot_i=0;
			L sum=0;
			for(int i=1;i<=sz;++i){
				auto [x,y]=calc(i, mid);
				sum+=y;
				tot_i+=x;
			}
			//dbg(mid, sum, tot_i, tot_used);
			if(1LL*tot_i*W1 + 1LL*W2*tot_used <= B){
				ret=max(ret, sum+tmp);
				//l=mid;
				return tuple<int,int,ll>(1, tot_i, sum+tmp);
			}else{
				return tuple<int,int,ll>(0, 0LL, 0LL);
			}
		};
		while(l<r){
			ll mid=(l+r)/2;
			if(get<0>(work(mid))) r=mid;
			else l=mid+1;
		}
		auto [_1, t1, s1]=work(l);
		if(l){
			//auto [_2, t2, s2]=work(l-1);
			int mx=(B-W2*tot_used)/W1;
			dbg(mx-t1,s1+(mx-t1)*(l-1));
			s1 += (mx - t1) * (l-1);
			ret=max(ret, s1);
		}
	}else{
		int j;
		for(j=i+1;j<=sz;++j)
			if(used[j] && a[tc[i]] >= a[tc[j]]) break;
		if(j<=sz) {
			used[i]=1;
			dfs(i-1);
			used[i]=0;
		}else{
			dfs(i-1);
			used[i]=1;
			dfs(i-1);
			used[i]=0;
		}
	}
}
ll solve(){
	C=1;
	for(int i=1;i<=n;++i){
		char u;
		int x;
		cin>>u>>x;
		if(u=='*' && x==1) {--n,--i;}
		else{
			b[i]=u;
			a[i]=x;
			if(u=='*') C*=x;
		}
	}
	for(int i=0;i<=sz;++i) c[i].clear();
	sz=0;
	ll ans=C;
	ll now=1;
	for(int i=1;i<=n;++i) {
		if(b[i]=='+') {
			if(now==1) ans+=C*a[i];
			else{
				c[sz].push_back(a[i]);
			}
		}else{
			tr[i]=++sz;
			tc[sz]=i;
			c[sz].push_back(0);
			now*=a[i];
		}
	}
	for(int i=1;i<=sz;++i) {
		sort(c[i].begin(), c[i].end(), greater<int>());
		sc[i].resize(c[i].size());
		sc[i][0]=c[i][0];
		for(int j=1;j<c[i].size();++j){
			sc[i][j]=sc[i][j-1]+c[i][j];
		}
	}
	ret=0;
	dfs();
	return ret+ans;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>n>>B>>W1>>W2){
		cout<<solve()<<"\n";
	}
}