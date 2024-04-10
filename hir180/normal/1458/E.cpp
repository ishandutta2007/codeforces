//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
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

int n, m;
set<pair<ll,ll>>zero;
map<int, vector<P>>M;
bool ans[100005];

bool not_in(int z){
	auto it = zero.lower_bound(mp(z+1, -1));
	if(it == zero.begin()) return 1;
	it--;
	if((*it).fi <= z && z <= (*it).sc) return 0;
	else return 1;
}
int main(){
	cin >> n >> m;
	rep(i, n){
		int x, y; cin >> x >> y;
		M[x].pb(mp(y, -1));
	}
	rep(i, m){
		int x, y; cin >> x >> y;
		M[x].pb(mp(y, i));
	}
	int pre = -1;
	zero.insert(mp(-INF, -1));
	//return 0;
	for(const auto a:M){
		int x = a.fi;
		vector<P>info = a.sc;
		
		//pre+1 ~ x-1
		if(pre+1 <= x-1){
			int zan = (x-1) - (pre+1) + 1;
			while(zero.size() >= 2 && zan > 0){
				auto it = zero.begin(); int l = (*it).fi, L = (*it).sc;
				it++; int R = (*it).fi, r = (*it).sc;
				zero.erase(it); zero.erase(zero.begin());
				
				if(R-L-1 <= zan){
					zan -= R-L-1;
					zero.insert(mp(l, r));
				}
				else{
					zero.insert(mp(l, L+zan));
					zero.insert(mp(R, r));
					zan = 0;
				}
			}
			if(zan > 0){
				auto it = zero.begin(); P p = *it; zero.erase(it);
				p.sc += zan;
				zero.insert(p); zan = 0;
			}
		}
		while(zero.size() >= 2){
			auto it = zero.begin(); int l = (*it).fi, L = (*it).sc;
			it++; int R = (*it).fi, r = (*it).sc;
			if(L+1 == R){
				zero.erase(it); zero.erase(zero.begin());
				zero.insert(mp(l, r));
			}
			else{
				break;
			}
		}
		auto it = zero.begin(); int l = (*it).fi, L = (*it).sc;
		int cur = L+1; bool ok = 0;
		set<int>cur_bad;
		for(const auto cs:info){
			int za = cs.fi, ty = cs.sc;
			if(ty != -1) continue;
			cur_bad.insert(za);
			if(cur >= za) ok = 1;
			if(not_in(za)) zero.insert(mp(za, za));
		}
		if(!ok){
			cur_bad.insert(cur);
			zero.insert(mp(cur, cur));
		}
		for(const auto cs:info){
			int za = cs.fi, ty = cs.sc;
			if(ty == -1) continue;
			ans[ty] = cur_bad.find(za) == cur_bad.end();
		}
		pre = x;
		//cout << x << endl;
		//for(const auto at:zero)cout<<at.fi<<" "<<at.sc<<endl;
		//cout<<"____"<<endl;
	}
	rep(i, m){
		cout<<(ans[i]?"WIN":"LOSE")<<'\n';
	}
}