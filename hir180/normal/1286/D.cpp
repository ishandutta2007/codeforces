#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 998244353;
int n;
ll zx[(1<<17)];
ll v[(1<<17)];
ll p[(1<<17)];
vector<pair<pair<ll,ll>,int>>za;
bool cmp(const pair<pair<ll,ll>,int>&aa,const pair<pair<ll,ll>,int>&ab){
	pair<ll,ll>a = aa.fi;
	pair<ll,ll>b = ab.fi;
	//a.fi / a.sc < b.fi / b.sc
	if(a.fi*b.sc != a.sc*b.fi) return a.fi * b.sc < a.sc * b.fi;
	else return aa.sc < ab.sc;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll rev;
int found(pair<pair<ll,ll>,int>p){
    int x = -1, y = za.size();
    while(x+1 < y){
        int m = (x+y)/2;
        if(za[m] == p) return m;
        if(cmp(za[m],p)) x = m;
        else y = m;
    }
    cout << p.fi.fi << " " << p.fi.sc << " " << p.sc << endl;
    rep(i,za.size()) cout << za[i].fi.fi << " " << za[i].fi.sc << " " << za[i].sc << endl;
    assert(false);
}
struct kaede{
	int prob[2][2][(1<<18)];
	vector<int>cand[(1<<18)];
	vector<int>num[2][2][(1<<18)];
	void add(int a,int k,int l,int r,int v){
		if(l <= a && a+1 <= r){
			cand[k].pb(v);
		}
		else return;
		if(l <= a && a <= (l+r)/2) add(a,k*2+1,l,(l+r)/2,v);
		else add(a,k*2+2,1+(l+r)/2,r,v);
	}
	void add(int pos,int val){
		add(pos,0,0,(1<<17)-1,val);
	}
	void make(){
		rep(i,(1<<18)){
			//not collide
			cand[i].pb(INF);
			SORT(cand[i]);
			rep(x,2) rep(y,2) num[x][y][i].resize(cand[i].size(),0);
		}
	}
	void solve(int k,int l,int r){
		if(l+1 == r){
			rep(x,2) rep(y,2){
				prob[x][y][k] = (1LL * (x==1?p[l]:(mod+1-p[l])) * (y==1?p[r]:(mod+1-p[r])) )% mod;
				ll dif = zx[r]-zx[l];
				if(l >= n-1){
				    num[x][y][k].back() += prob[x][y][k];
				}
				else if(x == 1 && y == 0){
					int a = found(mp(mp(dif,v[l]+v[r]),l));
					int b = POSL(cand[k],a);
					num[x][y][k][b] += prob[x][y][k];
				}
				else if(x == 0 && y == 0 && v[l] < v[r]){
					int a = found(mp(mp(dif,v[r]-v[l]),l));
					int b = POSL(cand[k],a);
					num[x][y][k][b] += prob[x][y][k];
				}
				else if(x == 1 && y == 1 && v[l] > v[r]){
					int a = found(mp(mp(dif,v[l]-v[r]),l));
					int b = POSL(cand[k],a);
					num[x][y][k][b] += prob[x][y][k];
				}
				else num[x][y][k].back() += prob[x][y][k];
			}
			return;
		}
		
		solve(k*2+1,l,(l+r)/2);
		solve(k*2+2,(l+r)/2+1,r);
		
		rep(a,2)rep(b,2){
			prob[a][b][k] = (1LL * (a==1?p[l]:(mod+1-p[l])) * (b==1?p[r]:(mod+1-p[r]))) % mod;
			rep(x,2)rep(y,2){
				//a,x & y,b
				ll sum1 = prob[a][x][k*2+1];
				ll sum2 = prob[y][b][k*2+2];
				vector<int>add; add.resize(cand[k].size(),0);
				int nxt1 = 0, nxt2 = 0;
				rep(i,cand[k].size()){
					if(i+1 == cand[k].size()){
						add[i] = sum1*sum2%mod;
					}
					else if(za[cand[k][i]].sc == (l+r)/2) continue;
					else{
						int aa = nxt1;
						if(aa < cand[k*2+1].size() && cand[k*2+1][aa] == cand[k][i]){
							//from left
							add[i] = sum2 * num[a][x][k*2+1][aa] % mod;
							sum1 -= num[a][x][k*2+1][aa];
							if(sum1 < 0) sum1 += mod;
							nxt1++;
						}
						else{
							aa = nxt2;
							assert(aa < cand[k*2+2].size() && cand[k*2+2][aa] == cand[k][i]);
							add[i] = sum1 * num[y][b][k*2+2][aa] % mod;
							sum2 -= num[y][b][k*2+2][aa];
							if(sum2 < 0) sum2 += mod;
							nxt2++;
						}
					}
				}
				
				ll dif = zx[(l+r)/2+1]-zx[(l+r)/2];
				
				if((l+r)/2 >= n-1){
				    rep(i,cand[k].size()){
				        num[a][b][k][i] += add[i];
				        if(num[a][b][k][i] >= mod) num[a][b][k][i] -= mod;
				    }
				}
				else if(x == 1 && y == 0){
					int aa = found(mp(mp(dif,v[(l+r)/2]+v[(l+r)/2+1]),(l+r)/2));
					int bb = POSL(cand[k],aa);
					assert(cand[k][bb] == aa);
					rep(i,bb+1){
					    num[a][b][k][i] += add[i];
				        if(num[a][b][k][i] >= mod) num[a][b][k][i] -= mod;
				    }
					for(int i=bb+1;i<cand[k].size();i++){
						num[a][b][k][bb] += add[i];
						if(num[a][b][k][bb] >= mod) num[a][b][k][bb] -= mod;
					}
				}
				else if(x == 0 && y == 0 && v[(l+r)/2] < v[(l+r)/2+1]){
					int aa = found(mp(mp(dif,v[(l+r)/2+1]-v[(l+r)/2]),(l+r)/2));
					int bb = POSL(cand[k],aa);assert(cand[k][bb] == aa);
					rep(i,bb+1){
					    num[a][b][k][i] += add[i];
				        if(num[a][b][k][i] >= mod) num[a][b][k][i] -= mod;
				    }
					for(int i=bb+1;i<cand[k].size();i++){
						num[a][b][k][bb] += add[i];
						if(num[a][b][k][bb] >= mod) num[a][b][k][bb] -= mod;
					}
				}
				else if(x == 1 && y == 1 && v[(l+r)/2] > v[(l+r)/2+1]){
					int aa = found(mp(mp(dif,v[(l+r)/2]-v[(l+r)/2+1]),(l+r)/2));
					int bb = POSL(cand[k],aa);assert(cand[k][bb] == aa);
					rep(i,bb+1){
					    num[a][b][k][i] += add[i];
				        if(num[a][b][k][i] >= mod) num[a][b][k][i] -= mod;
				    }
					for(int i=bb+1;i<cand[k].size();i++){
						num[a][b][k][bb] += add[i];
						if(num[a][b][k][bb] >= mod) num[a][b][k][bb] -= mod;
					}
				}
				else{
				    rep(i,cand[k].size()){
				        num[a][b][k][i] += add[i];
				        if(num[a][b][k][i] >= mod) num[a][b][k][i] -= mod;
				    }
				}
			}
		}
	}
}kaede;
int main(){
	scanf("%d",&n); //n = 100000;
	rep(i,n){
	    //zx[i] = i; v[i] = i; p[i] = i%101; 
		scanf("%lld%lld%lld",&zx[i],&v[i],&p[i]);
		p[i] = p[i] * modpow(100ll,mod-2) % mod;
	}
	
	for(int i=n;i<(1<<17);i++){
		zx[i] = 1000000000+i;
		v[i] = 10000007;
		p[i] = 1;
	}
	
	rep(i,n-1){
		ll dif = zx[i+1]-zx[i];
		za.pb(mp(mp(dif,v[i]+v[i+1]),i));
		if(v[i] > v[i+1]){
			za.pb(mp(mp(dif,v[i]-v[i+1]),i));
		}
		else if(v[i] < v[i+1]){
			za.pb(mp(mp(dif,v[i+1]-v[i]),i));
		}
	}
	sort(za.begin(),za.end(),cmp);
	
	rep(i,za.size()){
		int pos = za[i].sc;
		kaede.add(pos,i);
	}
	
	kaede.make();
	
	kaede.solve(0,0,(1<<17)-1);
	
	
	ll ret = 0;
	rep(i,za.size()){
		rep(x,2)rep(y,2){
			ret += za[i].fi.fi * modpow(za[i].fi.sc,mod-2) % mod * kaede.num[x][y][0][i] % mod;
		}
	}
	cout << (ret%mod+mod)%mod << endl;
}