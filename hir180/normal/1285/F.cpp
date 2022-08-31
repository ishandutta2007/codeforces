//Let's join Kaede Takagaki Fun Club !!
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
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

int n, cntt[100005];
vector<int>vi;
vector<int>pr[100005], lst[100005];
vector<P>check[100005];
ll ans;
int zcnt[100005];

int main(){
	scanf("%d",&n);
	repn(i,n){
		int a; scanf("%d",&a); cntt[a]++;
	}
	rep(i,100005){
		if(cntt[i] >= 2) ans = i;
		if(cntt[i]) vi.pb(i);
	}
	n = vi.size();
	
	for(int i=2;i<100005;i++){
		if(pr[i].size()) continue;
		
		for(int j=1;i*j<100005;j++) pr[i*j].pb(i);
	}
	for(int i=1;i<100005;i++){
		int sz = pr[i].size();
		rep(mask,(1<<sz)){
			int num = 1;
			rep(j,sz) if(((mask>>j)&1)) num = num * pr[i][j];
			int f = (__builtin_popcount(mask)%2 == 0 ? 1 : -1);
			check[i].pb(mp(num, f));
		}
	}
	auto cnt = [&](int v){
		int ret = 0;
		for(auto at:check[v]){
			ret += at.sc * zcnt[at.fi];
		}
		return ret;
	};
	auto process = [&](int v, int ty){
		for(auto at:check[v]){
			zcnt[at.fi] += (ty == 1 ? 1 : -1);
		}
	};
	auto solve = [&](vector<int>&vi, int gcd){
		if(vi.size() < 2) return -1LL;
		//o(gcd); dmp(vi);
		ll ret = 0;
		stack<int>st;
		rep(i,vi.size()){
			int have = cnt(vi[i]);
			if(!have){
				st.push(vi[i]);
				process(vi[i], 1);
			}
			else{
				while(have){
					int s = st.top(); st.pop();
					process(s, 0);
					if(__gcd(s, vi[i]) == 1){
						ret = max(ret, 1LL*s*vi[i]);
						have--;
					}
				}
			}
		}
		while(st.size()){
		    int s = st.top(); st.pop();
			process(s, 0);
		}
		return ret * gcd;
	};
	for(int i=1;i<100005;i++){
		for(int j=1;i*j<100005;j++){
			if(cntt[i*j]){
				lst[i].pb(j);
			}
		}
		reverse(all(lst[i]));
		ll ret = solve(lst[i], i);
		if(ans < ret) ans = ret;
	}
	printf("%lld\n",ans);
}