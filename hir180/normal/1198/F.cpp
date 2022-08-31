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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}

int n;
vector<int>pr;
bool bad[32000];
int a[100005];
bool dp[512][512];
P1 pre[512][512];
int ans[100005];

int main(){
	double B = clock();
	for(int i=2;i<32000;i++){
		if(bad[i]) continue;
		pr.pb(i);
		for(int j=2;i*j<32000;j++){
			bad[i*j] = 1;
		}
	}
	scanf("%d",&n);
	rep(i,n) {
	    scanf("%d",&a[i]);
	}
	
	mt19937 mt(114514);
	vector<int>v; v.resize(n); rep(i,n) v[i] = i;
	
	while(clock()-B <= 0.3*CLOCKS_PER_SEC){
		shuffle(v.begin(),v.end(),mt);
		int x = a[v[0]], y = a[v[1]];
		vector<int>p[2];
		rep(i,pr.size()){
			if(x%pr[i] != 0) continue;
			p[0].pb(pr[i]);
			while(x%pr[i] == 0) x/=pr[i];
		}
		if(x > 1) p[0].pb(x);
		
		rep(i,pr.size()){
			if(y%pr[i] != 0) continue;
			p[1].pb(pr[i]);
			while(y%pr[i] == 0) y/=pr[i];
		}
		if(y > 1) p[1].pb(y);
		x = v[0], y = v[1];
		int s = p[0].size(), t = p[1].size();
		assert(s <= 9 && t <= 9);
		memset(dp,0,sizeof(dp));
		dp[(1<<s)-1][(1<<t)-1] = 1;
		vector<int>ers[2][9],cand;
		rep(i,n){
			if(i == x || i == y) continue;
			rep(k,p[0].size()) if(a[i]%p[0][k] != 0 && ers[0][k].size() < 15) ers[0][k].pb(i);
			rep(k,p[1].size()) if(a[i]%p[1][k] != 0 && ers[1][k].size() < 15) ers[1][k].pb(i);
		}
		rep(i,s) if(ers[0][i].size() == 0) continue;
		rep(i,t) if(ers[1][i].size() == 0) continue;
		rep(i,2)rep(j,9) rep(k,ers[i][j].size()) cand.pb(ers[i][j][k]);
		vector<P>candM;
		SORT(cand); ERASE(cand);
		rep(i,cand.size()){
			int v;
			v = 0;
			rep(j,s) if(a[cand[i]]%p[0][j] == 0) v ^= (1<<j);
			int u;
			u = 0;
			rep(j,t) if(a[cand[i]]%p[1][j] == 0) u ^= (1<<j);
			candM.pb(mp(v,u));
		}
		rep(q,cand.size()){
			int v = cand[q];
			rep(m1,(1<<s)){
				rep(m2,(1<<t)){
					if(dp[m1][m2] == 0) continue;
					int nwa = (m1 & candM[q].fi), nwb = (m2 & candM[q].sc);
					if(m1 != nwa && dp[nwa][m2] == false){
						dp[nwa][m2] = 1;
						pre[nwa][m2] = mp(v,P(m1,m2));
					}
					if(m2 != nwb && dp[m1][nwb] == false){
						dp[m1][nwb] = 1;
						pre[m1][nwb] = mp(v,mp(m1,m2));
					}
				}
			}
		}
		if(dp[0][0] == false) continue;
		P cur = mp(0,0);
		set<int>S;
		while(cur != mp((1<<s)-1, (1<<t)-1)){
			int x = pre[cur.fi][cur.sc].fi;
			int na = pre[cur.fi][cur.sc].sc.fi;
			int nb = pre[cur.fi][cur.sc].sc.sc;
			assert(S.find(x) == S.end());
			S.insert(x);
			if(na != cur.fi){
			    assert(na > cur.fi && nb == cur.sc);
				ans[x] = 1;
				cur.fi = na;
			}
			else{
				assert(nb > cur.sc);
				ans[x] = 2;
				cur.sc = nb;
			}
		}
		ans[x] = 1;
		ans[y] = 2;
		rep(i,n) if(ans[i] == 0) ans[i] = 1;
		puts("YES");
		rep(i,n) printf("%d\n",ans[i]);
		return 0;
	}
	puts("NO");
}