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
const ll mod = 998244353;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

int n,q,a[200005];
vector<array<int,4>>cand;
int mn[200005],mx[200005];

struct BIT
{
	int seg[(1<<19)];
	int SZ;
	void init(int sz){
		SZ = 1;
		while(SZ < sz+3) SZ <<= 1;
		rep(i,SZ*2) seg[i] = INF;
	}
	void update(int pos,int v){
		pos += SZ-1;
		seg[pos] = v;
		while(pos ){
			pos = (pos-1)/2;
			seg[pos] = min(seg[pos*2+1], seg[pos*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r < a || b < l) return INF;
		if(a <= l && r <= b) return seg[k];
		return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,1+(l+r)/2,r));
	}
	int query(int a,int b){ return query(a,b,0,0,SZ-1); }
	//aSindex
	int find_left(int a,int b,int k,int l,int r,int S){
		if(r < a || b < l) return -1;
		if(a <= l && r <= b){
			if(seg[k] >= S) return -1;
			if(l == r) return l;
		}
		int ret = find_left(a,b,k*2+2,(l+r)/2+1,r,S);
		if(ret != -1) return ret;
		return find_left(a,b,k*2+1,l,(l+r)/2,S);
	}
	int query(int a,int b,int S){
		return find_left(a,b,0,0,SZ-1,S);
	}
}kaede;

void solve(int id, int l, int r){
	vector<P>vec;
	for(int i=l;i<=r;i++){
		vec.pb(mp(a[i], i));
	}
	SORT(vec);
	kaede.init(r-l+2);
	rep(i,vec.size()){
		int pos = vec[i].sc;
		{
			if(mx[pos] > l){
				int a = kaede.query(0, mx[pos]-1, pos);
				if(a > 0){
					if(!id){
						cand.pb({a, min(mn[a], mx[pos]), max(mn[a], mx[pos]), pos});
					}
					else{
						cand.pb({n+1-pos, n+1-max(mn[a], mx[pos]), n+1-min(mn[a], mx[pos]), n+1-a});
					}
				}
			}
		}
		{
			if(mn[pos] <= r){
				kaede.update(pos, mn[pos]);
			}
		}
	}
}
void calc(int id){
	//le <= ri
	stack<P>S;
	repn(i,n){
		while(S.size() && S.top().fi > a[i]){
			mn[S.top().sc] = i;
			S.pop();
		}
		S.push(mp(a[i],i));
	}
	while(S.size()){
		mn[S.top().sc] = INF;
		S.pop();
	}
	
	for(int i=n;i>=1;i--){
		while(S.size() && S.top().fi < a[i]){
			mx[S.top().sc] = i;
			S.pop();
		}
		S.push(mp(a[i],i));
	}
	while(S.size()){
		mx[S.top().sc] = -INF;
		S.pop();
	}
	solve(id, 1, n);
}
array<int,4>ans[200005];
vector<int>up,dw;
int main(){
	scanf("%d%d",&n,&q);
	repn(i,n) scanf("%d",&a[i]);
	repn(i,n-1){
		if(a[i] < a[i+1]) up.pb(i);
		if(a[i] > a[i+1]) dw.pb(i);
	}
	calc(0);
	reverse(a+1, a+n+1);
	calc(1);
	reverse(a+1, a+n+1);
	
	rep(i,200005) ans[i][3] = INF;
	for(int i=0;i<cand.size();i++){
		if(ans[cand[i][0]][3] > cand[i][3]){
			ans[cand[i][0]] = cand[i];
		}
	}
	for(int i=n-1;i>=1;i--){
		if(ans[i][3] > ans[i+1][3]) ans[i] = ans[i+1];
	}
	rep(i,q){
		int a,b; scanf("%d%d",&a,&b);
		if(ans[a][3] <= b){
			puts("4");
			printf("%d %d %d %d\n",ans[a][0],ans[a][1],ans[a][2],ans[a][3]);
		}
		else{
			int p = POSL(up, a);
			int q = POSL(dw, a);
			if(up.size() > p && up[p] < b && dw.size() > q && dw[q] < b){
				if(up[p] < dw[q]){
					p = POSL(up, dw[q]);
					p --;
					puts("3");
					printf("%d %d %d\n",up[p], up[p]+1, dw[q]+1);
				}
				else{
					q = POSL(dw, up[p]);
					q --;
					puts("3");
					printf("%d %d %d\n",dw[q], dw[q]+1, up[p]+1);
				}
			}
			else{
				puts("0\n");
			}
		}
	}
}