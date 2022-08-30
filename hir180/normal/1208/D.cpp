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
int n;
ll a[200005];
int ans[200005];

struct BIT
{
	ll bit[200005];
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		for(int s=i;s<200005;s+=f(s)) bit[s]+=x;
	}
	ll sum(int i)
	{
		ll res=0;
		for(int s=i;s>0;s-=f(s)) res+=bit[s];
		return res;
	}
}kaede;

int main(){
	g(n);
	repn(i,n) g(a[i]);
	repn(i,n) kaede.add(i,i);
	for(int i=n;i>=1;i--){
		int lb = 0, ub = n+1;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			if(kaede.sum(mid) > a[i]) ub = mid;
			else lb = mid;
		}
		ans[i] = ub;
		kaede.add(ub,-ub);
	}
	repn(i,n) o(ans[i]);
}