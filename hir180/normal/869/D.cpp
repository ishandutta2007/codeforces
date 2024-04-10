#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
int a[5],b[5];
set<int>S;
bool ok = 1;
int lca(int x,int y){
	if(x==y)return x;
	int u,v;
	rep(i,31) if(((x>>i)&1)) u=i;
	rep(i,31) if(((y>>i)&1)) v=i;
	if(u>v){
		swap(u,v); swap(x,y);
	}
	while(u<v){
		y/=2; v--;
	}
	if(x==y) return x;
	int ans = 0;
	for(int i=u;i>=0;i--){
		if( ((x>>i)&1) + ((y>>i)&1) == 1 ){
			return ans;
		}
		ans = ans*2+((x>>i)&1);
	}
	return ans;
}
vector<int>path(int u,int v){
	vector<int>A,B;
	int x = lca(u,v);
	while(u != x){
		A.pb(u);
		u/=2;
	}
	A.pb(x);
	while(v != x){
		B.pb(v);
		v/=2;
	}
	reverse(B.begin(),B.end());
	rep(i,B.size()) A.pb(B[i]);
	return A;
}
ll C(ll top){
	if(top>n) return 0;
	ll L = top,R = top,ret = 0;
	while(1){
		if(R >= n){
			if(L<=n) ret += (n-L+1);
			return ret;
		}
		ret += R-L+1;
		L*=2;
		R=R*2+1;
	}
}
ll cnt(ll top,vector<P>vec){
	if(top>n) return 0;
	if(S.find(top)!=S.end()) return 0LL;
	vector<int>L;
	for(int i=0;i<vec.size();i++){
		L.pb(lca(vec[i].fi,vec[i].sc));
	}
	SORT(L); ERASE(L);
	ll ret = C(top);
	for(int i=0;i<L.size();i++){
	    if(lca(top,L[i])!=top) continue;
		for(int j=0;j<L.size();j++){
			if(i==j) continue;
			if(lca(top,L[j])!=top) continue;
			if(lca(L[i],L[j]) == L[j]) goto fail;
		}
		ret -= C(L[i]); fail:;
	}
	return ret;
}
void go(int u,int v){
	vector<int>A,B;
	int x = lca(u,v);
	while(u != x){
		A.pb(u);
		u/=2;
	}
	A.pb(x);
	while(v != x){
		B.pb(v);
		v/=2;
	}
	reverse(B.begin(),B.end());
	rep(i,B.size()) A.pb(B[i]);
	for(int i=0;i<A.size();i++){
		if(S.find(A[i]) != S.end()){
			ok = 0;
		}
		else S.insert(A[i]);
	}
}
bool in(int u,int v){
	vector<int>A,B;
	int x = lca(u,v); //cout<<u<<v<<endl;
	while(u != x){
		A.pb(u);
		u/=2;
	}
	A.pb(x);
	while(v != x){
		B.pb(v);
		v/=2;
	}
	reverse(B.begin(),B.end());
	rep(i,B.size()) A.pb(B[i]);
	for(int i=0;i<A.size();i++){
		if(S.find(A[i]) != S.end()) return 0;
	}
	return 1;
}
ll calc(int top,vector<P>vec){
	if(top>n) return 0;
	if(S.find(top)!=S.end()) return 0LL;
	while(top != 1){
		int top2 = top/2;
		if(S.find(top2) != S.end()) return cnt(top,vec);
		top = top2;
	}
	return cnt(1,vec);
}
ll calc2(int u,int v,vector<P>vec){
    if(S.find(u)!=S.end()) return 0LL;
    if(S.find(v)!=S.end()) return 0LL;
    if(u==v) return 0LL;
	vector<int>pat = path(u,v); //cout<<u<<v<<pat.size()<<endl; return 0;
	//cout<<pat[0]<<pat[1]<<endl; return 0;
	int x = lca(u,v); //cout<<x<<endl;
	vector<ll>cntt; //cout<<pat.size()<<endl;//return 0;
	for(int i=0;i<pat.size();i++){
	    assert(S.find(pat[i])==S.end());
		if(pat[i] != x){
			int y = 2*pat[i],z = 2*pat[i]+1;
			int a = (i==0?-1:pat[i-1]);
			int b = (i==pat.size()-1?-1:pat[i+1]);
		//	if(pat[i]==3){cout<<y<<z<<a<<b<<endl;}
			ll C = 1;
			if(y==a || y==b); else C+=cnt(y,vec);
			if(z==a || z==b); else C+=cnt(z,vec);
			//cout<<cnt(6,vector<P>())<<endl;
			//cout<<cnt(7,vector<P>())<<endl;
		//	if(C==-5)cout<<y<<z<<"M"<<endl;
			cntt.pb(C);
		}
		else{
			int y = 2*pat[i],z = 2*pat[i]+1;
			int a = (i==0?-1:pat[i-1]);
			int b = (i==pat.size()-1?-1:pat[i+1]);
			ll C = 1;
			if(y==a || y==b); else C+=cnt(y,vec);
			if(z==a || z==b); else C+=cnt(z,vec);
			int X = x;
			int pre = x;
			while(X != 1){
				int XX = X/2;
				if(S.find(XX) != S.end()) break;
				C++;
				y = 2*XX,z = 2*XX+1;
				if(y==pre); else C+=cnt(y,vec);
				if(z==pre); else C+=cnt(z,vec);
				pre = XX; X = XX;
			}
			cntt.pb(C);
		}
	}
	//for(int i=0;i<cntt.size();i++) cout<<cntt[i]<<" ";cout<<endl;
	ll ret = 0,sum = 0;
	for(int i=1;i<cntt.size();i++){
		sum += cntt[i-1]; sum%=mod;
		ret += sum*cntt[i]%mod;
	}
	return ret%mod;
}
int main(){
	cin>>n>>m;
	rep(i,m)cin>>a[i]>>b[i];
	ll ret = 1LL*n*n;
	for(int i=1;i<=m;i++){
		for(int j=0;j<(1<<m);j++){
			if(__builtin_popcount(j) != i) continue;
			vector<int>vi;
			rep(k,m) if(((j>>k)&1)) vi.pb(k);
			do{
				for(int k=0;k<(1<<i);k++){
					int x[5];
					for(int e=0;e<i;e++) x[e] = (((k>>e)&1));
					vector<P>vec;
					for(int y=0;y<vi.size();y++){
						if(x[y]){
							vec.pb(mp(a[vi[y]],b[vi[y]]));
						}
						else{
							vec.pb(mp(b[vi[y]],a[vi[y]]));
						}
					}
					S.clear(); ok = 1;
					vector<P>vec2;
					for(int i=1;i<vec.size();i++){
						go(vec[i-1].sc,vec[i].fi);
						vec2.pb(mp(vec[i-1].sc,vec[i].fi));
					}
					if(ok == 0) continue;
					bool D = in(vec[0].fi,vec[vec.size()-1].sc);
					if(vec[0].fi==vec[vec.size()-1].sc) continue;
					if(D == 0){
					    //cout<<vec.size()<<endl;
						ret += calc(vec[0].fi,vec2) * calc(vec[vec.size()-1].sc,vec2) % mod;
						//cout<<vec[0].fi<<" "<< calc(vec[0].fi,vec2)<<endl;
						//cout<<vec[vec.size()-1].sc<<" "<<calc(vec[vec.size()-1].sc,vec2)<<endl;
						//cout<<calc(vec[0].fi,vec2)<<" "<<calc(vec[vec.size()-1].sc,vec2)<<endl;
						ret %= mod;
					}
					else{
					    //cout<<vec.size()<<endl;
					    //cout<<vec[0].fi<<" " <<vec[0].sc<<" "<<vec[1].fi<<" " <<vec[1].sc<<endl;
					    //cout<<"N"<<endl;
					    //cout<<vec.size()<<endl;
						ret += calc2(vec[0].fi,vec[vec.size()-1].sc,vec2);
						//cout<<calc2(vec[0].fi,vec[vec.size()-1].sc,vec2)<<endl;
						ret %= mod;
					}
				}
			}while(next_permutation(vi.begin(),vi.end()));
		}
	}
	cout<<ret%mod<<endl;
}