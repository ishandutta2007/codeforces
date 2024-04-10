//Let's join Kaede Takagaki Fun Club !!
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
struct ss{
	#define s (1<<19)
	int seg[s*2];
	void init(){
		fill(seg, seg+s*2, INF+7);
	}
	void update(int beg,int end,int idx,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)
		{
			return ;
		}
		if(beg<=lb&&ub<=end)
		{
			chmin(seg[idx],num);
			return ;
		}
		update(beg,end,idx*2+1,lb,(lb+ub)/2,num);
		update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num);
	}
	int query(int a,int idx,int lb,int ub)
	{
		if(lb == ub) return seg[idx];
		if(lb <= a && a <= (lb+ub)/2) return min(seg[idx], query(a,idx*2+1,lb,(lb+ub)/2));
		else return min(seg[idx], query(a,idx*2+2,1+(lb+ub)/2,ub));
	}
}kaede;

int n,a[500005];
vector<P>za;
bool sm[500005];
int main(){
	ios::sync_with_stdio(false);
	g(n);
	repn(i,n){
		g(a[i]);
		za.pb(mp(a[i],i));
	}
	kaede.init();
	set<int>cut;
	for(int i=0;i<=n;i++) cut.insert(i);
	SORT(za);
	int ans = 0,prebeg = 0;
	rep(i,za.size()){
		int v = za[i].sc;
		bool las = 0;
		if(i == za.size()-1 || za[i].fi != za[i+1].fi) las = 1;
		if(v-1 > 0 && !sm[v-1]){
			cut.erase(v-1);
		}
		else if(v-1 > 0 && sm[v-1]){
			cut.insert(v-1);
		}
		if(v+1 <= n && !sm[v+1]){
			cut.erase(v);
		}
		else if(v+1 <= n && sm[v+1]){
			cut.insert(v);
		}
		sm[v] = 1;
		if(las){
			for(int j=prebeg;j<=i;j++){
				int v = za[j].sc;
				auto it = cut.lower_bound(v);
				rep(q,2){
					if(it == cut.end()) break;
					int a = *(--it) + 1;
					int b = *(++it);
					if(a%2 == b%2){
						if(sm[a]) kaede.update(a,b,0,0,s-1,za[i].fi);
					}
					else{
						assert(sm[a] != sm[b]);
						if(sm[a]) kaede.update(a,(a+b)/2,0,0,s-1,za[i].fi);
						else kaede.update(1+(a+b)/2,b,0,0,s-1,za[i].fi);
					}
					chmax(ans, (b-a)/2);
					it++;
				}
				it = cut.lower_bound(v);
				rep(q,2){
					if(it == cut.begin()) break;
					int a = *(--it) + 1;
					int b = *(++it);
					if(a%2 == b%2){
						if(sm[a]) kaede.update(a,b,0,0,s-1,za[i].fi);
					}
					else{
						assert(sm[a] != sm[b]);
						if(sm[a]) kaede.update(a,(a+b)/2,0,0,s-1,za[i].fi);
						else kaede.update(1+(a+b)/2,b,0,0,s-1,za[i].fi);
					}
					chmax(ans, (b-a)/2);
					it--;
				}
			}
			prebeg = i+1;
		}
	}
	o(ans);
	repn(i,n) o(kaede.query(i,0,0,s-1));
}