#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=200011;
//int a[M],b[M],t;
vector<int> wk(int x){
	vector<int> r;
	for(int i=1;i*i<=x;++i) {
		if(x%i==0) {
			r.push_back(i);
			if(i!=1&&i*i<x) r.push_back(x/i);
		}
	}
	sort(r.begin(),r.end());
	return r;
}

int n;
struct P{
	int l,r,id;
} q[N];
ll ans[N];
ll c[N];

ll tot;
void add(int x,ll v){
	tot+=v;
	for(;x<N;x+=x&-x) c[x]+=v;
}
ll qry(int x){
	ll r=0;
	for(;x;x-=x&-x)r+=c[x];
	return r;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	For(i,0,n){
		int l,r;
		cin>>l>>r;
		q[i]=(P){l,r,i};
	}
	sort(q,q+n,[](P u,P v){
		return u.r<v.r;
	});
	int t=0;
	For(i,3,N){
		if(i%3==0){
			if(i%5==0) add(2*i/5,1);
			if(i%2==0) add(i/2,1);
		}
		auto a=wk(i);
		int m=a.size();
		for(int j=0;j<m;++j){
			add(a[j], m-j-1);
		}
		while(t<n&&q[t].r<=i) {
			auto [l,r,id]=q[t];
			ll ret=1LL*(r-l+1)*(r-l)*(r-l-1)/6;
			//dbg(id,tot);
			ret -= tot-qry(l-1);
			ans[id]=ret;
			t++;
		}
	}
	For(i,0,n) cout<<ans[i]<<"\n";
}