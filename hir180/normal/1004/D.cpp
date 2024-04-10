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
const ll mod = 1000000007;

int n,cnt[1000005],sum[1000005];
vector<int>dv;
int mx;

int main(){
	scanf("%d",&n);
	rep(i,n){
		int a; scanf("%d",&a);
		cnt[a]++; mx = max(mx,a);
	}
	int f = -1;
	if(cnt[0] != 1){
		puts("-1");
		return 0;
	}
	for(int i=1;;i++){
		if(cnt[i] != i*4){
			f = i;
			break;
		}
	}
	for(int i=1;i*i<=n;i++){
		if(n%i != 0) continue;
		dv.pb(i);
	}
	vector<P2>cand;
	rep(i,dv.size()){
		int a = dv[i], b = n/a;
		int sum = a+b-mx;
		if(sum <= 0) continue;
		repn(j,(a+1)/2){
			int p = j, q = sum-j;
			if(1 <= q && q <= (b+1)/2 && min(p,q) == f){
				cand.pb(mp(mp(a,b),mp(p,q)));
			}
		}
	}
	
	rep(i,cand.size()){
		int a = cand[i].fi.fi, b = cand[i].fi.sc;
		int p = cand[i].sc.fi, q = cand[i].sc.sc;
		memset(sum,0,sizeof(sum));
		repn(x,a) repn(y,b){
			int D = abs(x-p)+abs(y-q);
			sum[D]++;
			if(sum[D] > cnt[D]){
				goto nxt;
			}
		}
		cout<<a<<" "<<b<<" "<<p<<" "<<q<<endl;return 0;
		nxt:;
	}
	puts("-1");
}