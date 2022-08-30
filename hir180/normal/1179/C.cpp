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
#define INF 100000000
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
int n,m,a[300005],b[300005];
#define sz (1<<20)

struct s{
	int seg[sz*2];
	int lazy[sz*2];
	void lazy_evaluate(int k)
	{
		if(k*2+2>=sz*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2]+=lazy[k];
		seg[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	int update(int beg,int end,int idx,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx]+=num;
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return seg[idx]=max(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	int query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return -INF;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return max(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
	int find(int k, int l, int r){
		if(l == r) return l;
		if(lazy[k]) lazy_evaluate(k);
		
		if(seg[k*2+2] > 0) return find(k*2+2, (l+r)/2+1, r);
		else{
			assert(seg[k*2+1] > 0);
			return find(k*2+1, l, (l+r)/2);
		}
	}
	int ans(){
		if(seg[0] <= 0) return -2;
		return find(0, 0, sz-1);
	}
}kaede;

int main(){
	ios::sync_with_stdio(false);
	g(n); g(m);
	repn(i,n){
		g(a[i]); kaede.update(0, a[i]-1, 0, 0, sz-1, 1);
	}
	repn(i,m){
		g(b[i]); kaede.update(0, b[i]-1, 0, 0, sz-1, -1);
	}
	int q;
	g(q);
	rep(i,q){
		int id; g(id);
		if(id == 1){
			int v,x; g(v); g(x);
			kaede.update(0, a[v]-1, 0, 0, sz-1, -1);
			a[v] = x;
			kaede.update(0, a[v]-1, 0, 0, sz-1, 1);
		}
		else{
			int v,x; g(v); g(x);
			kaede.update(0, b[v]-1, 0, 0, sz-1, 1);
			b[v] = x;
			kaede.update(0, b[v]-1, 0, 0, sz-1, -1);
		}
		int a = kaede.ans();
		o(a+1);
	}
}