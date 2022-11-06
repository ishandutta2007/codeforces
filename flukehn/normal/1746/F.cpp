#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
using ll=long long;
#ifndef flukehn
#define dbg(...) 0
#define debug(...) 0
#endif
mt19937_64 rnd;
using ull=unsigned long long;
struct P{
	ull a[2];
	void gen(){
		For(i,0,2) a[i]=rnd();
	}
	bool operator[](int t){
		return a[t/64]>>(t%64)&1;
	}
};
const int N=3e5+11;
const int H=64;
int n;
struct BIT{
	int c[N];
	void add(int x,int v){
		for(;x<=n;x+=x&-x) c[x]+=v;
	}
	int qry(int x){
		int r=0;
		for(;x;x-=x&-x)r+=c[x];
		return r;
	}
} ;
int a[N];
BIT c[H];
map<int,P> f;
inline P F(int w){
	P t;
	if(!f.count(w)) {
		t.gen();
		f[w]=t;
	}else{
		t=f[w];
	}
	return t;
}
int query(){
	int l,r,k;
	cin>>l>>r>>k;
	if(k==1) return 1;
	For(j,0,H) if(c[j].qry(r) % k !=c[j].qry(l-1)%k) return 0;
	return 1;
}
int main(){
#ifdef flukehn
	freopen("A.in","r",stdin);
#endif
	rnd.seed(time(0));
	ios::sync_with_stdio(0),cin.tie(0);
	int Q;
	cin>>n>>Q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		P t=F(a[i]);
		For(j,0,H) if(t[j]) c[j].add(i,1);
	}
	while(Q--){
		int op;
		cin>>op;
		if(op==1){
			int i,x;
			cin>>i>>x;
			P u=F(a[i]);
			P v=F(x);
			a[i]=x;
			For(j,0,H) {
				int c=u[j];
				int d=v[j];
				if(c==d) continue;
				if(c) ::c[j].add(i,-1);
				else ::c[j].add(i,1);
			}
		}else{
			int r=query();
			if(r)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}