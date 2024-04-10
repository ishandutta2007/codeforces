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
#define all(x) x.begin(),x.end()
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
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(T a){
	cout << a << '\n';
}
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

int n,t;
vector<P1>vec;
vector<int>za;
bool killed[100005];
int dp[100005];

vector<int>check;
int curlen[100005], all[100005];
struct seg{
	int num[(1<<19)];
	void init(){
		memset(num, 0, sizeof(num));
	}
	void update(int a,int b,int k,int l,int r,int aa,bool inn){
		if(r < a || b < l || a > b) return;
		if(a <= l && r <= b && num[k] != -1){
			if(!inn){
				dp_upd(num[k], aa, r-l+1);
			}
			else{
				num[k] = aa;
			}
			return;
		}
		assert(l < r);
		if(num[k] != -1){
			num[k*2+1] = max(num[k*2+1], num[k]);
			num[k*2+2] = max(num[k*2+2], num[k]);
		}
		update(a,b,k*2+1,l,(l+r)/2,aa, inn);
		update(a,b,k*2+2,(l+r)/2+1,r,aa, inn);
		if(num[k*2+1] >= 0 && num[k*2+2] >= 0 && num[k*2+1] == num[k*2+2]){
			num[k] = num[k*2+1];
		}
		else{
			num[k] = -1;
		}
	}
	void dp_upd(int pre,int nxt,int len){
	    check.pb(pre);
		all[pre] = min(vec[pre].sc.sc, vec[nxt].sc.sc) - max(vec[pre].sc.fi, vec[nxt].sc.fi);
		curlen[pre] += len;
	}
}kaede;

int main(){
	scanf("%d%d",&n,&t);
	vec.resize(n+2);
	vec[0] = mp(0,mp(-INF,INF));
	vec[1] = mp(t,mp(-INF,INF));
	rep(i,n){
		scanf("%d%d%d",&vec[i+2].fi, &vec[i+2].sc.fi, &vec[i+2].sc.sc);
	}
	n+=2;
	SORT(vec);
	reverse(all(vec));
	rep(i,n){
		za.pb(vec[i].sc.fi);
		za.pb(vec[i].sc.sc);
	}
	SORT(za); ERASE(za);
	kaede.init();
	dp[0] = 2*INF;
	for(int i=0;i<vec.size();i++){
		vec[i].sc.fi = POSL(za, vec[i].sc.fi);
		vec[i].sc.sc = POSL(za, vec[i].sc.sc);
		if(!i) continue;
		check.clear();
		kaede.update(vec[i].sc.fi, vec[i].sc.sc-1, 0, 0, (1<<18)-1, i, false);
		rep(ii,check.size()){
			int a = check[ii];
			//cout << a << " " << i << " " << all[a] << " " << curlen[a] << endl;
			if(all[a] == curlen[a]){
				dp[i] = max(dp[i], min(dp[a], za[min(vec[a].sc.sc, vec[i].sc.sc)] - za[max(vec[a].sc.fi, vec[i].sc.fi)]));
			}
		}
		rep(i,check.size()){
		    int a = check[i];
			curlen[a] = 0;
			all[a] = 0;
		}
		kaede.update(vec[i].sc.fi, vec[i].sc.sc-1, 0, 0, (1<<18)-1, i, true);
	}
	printf("%d\n",dp[vec.size()-1]);
}