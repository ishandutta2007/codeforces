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
const ll mod = 998244353;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

const int maxn = 1000015, alpha = 26;
int len[maxn], link[maxn], to[maxn][alpha];
int slink[maxn], diff[maxn];
int sz, last, n;
char ch[maxn];
 
//0...0
//1...-1
//len... 
//link... suffix link1
//to... 
//diff...len[x]-len[link[x]]
//slink... diff (diffO(log N))
//series_ans... diffDPmin (O(1)O(log N))
 
void init(){
	n = last = 0;
	ch[n++] = -1;
	link[0] = 1;
	len[1] = -1;
	sz = 2;
}
//len[1] = -1-1
//
int get_link(int v){
	while(ch[n-len[v]-2] != ch[n-1]) v = link[v];
	return v;
}
//
void add_letter(char c){
	ch[n++] = c -= 'a';
	//
	last = get_link(last);
	
	//
	if(!to[last][c]){
		//
		len[sz] = len[last] + 2;
		link[sz] = to[get_link(link[last])][c];
		diff[sz] = len[sz] - len[link[sz]];
		
		//slink1
		//
		if(diff[sz] == diff[link[sz]]){
			slink[sz] = slink[link[sz]];
		}
		else{
			slink[sz] = link[sz];
		}
		//
		to[last][c] = sz++;
	}
	last = to[last][c];
}
string s;
P curmx;
int rmx[1000005];
void make(){
	int sz = s.size();
	for(int i=-1;i<sz;i++){
		if(i > sz-1-i) return;
		if(i == sz-1-i){
			curmx = mp(sz,0);
			return;
		}
		if(i >= 0 && s[i] != s[sz-1-i]) return;
		int x = i+1;
		int id = rmx[sz-2-i];
		int y = x+len[id];
		while(x+y > sz){
			if(x+x+len[slink[id]] <= sz){
				y -= (x+y-sz+diff[id]-1) / diff[id] * diff[id];
				break;
			}
			else{
				id = slink[id];
				id = link[id];
				y = x+len[id];
			}
		}
		if(curmx.fi+curmx.sc < x+y) curmx = P(x,y);
	}
}
void solve(){
	cin >> s;
	string ans = "";
	rep(i,2){
		init();
		rep(i,s.size()){
			add_letter(s[i]);
			rmx[i] = last;
		}
		curmx = mp(0,0);
		make();
		if(ans.size() < curmx.fi+curmx.sc){
			ans.clear();
			rep(i,curmx.fi) ans.pb(s[i]);
			rep(i,curmx.sc) ans.pb(s[s.size()-curmx.sc+i]);
		}
		int ii = 0;
		while(ii < ans.size()-1-ii){
		    assert(ans[ii] == ans[ans.size()-1-ii]);
		    ii++;
		}
		reverse(s.begin(),s.end());
		rep(i,sz+5)rep(j,26) to[i][j] = 0;
	}
	o(ans);
}
int main(){
	ios::sync_with_stdio(false);
	int t; g(t);
	while(t--) solve();
}