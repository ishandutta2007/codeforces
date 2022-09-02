#include <bits/stdc++.h>
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
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
priority_queue<ll,vector<ll>,greater<ll> >que;
int n;
ll x[100005],t[100005],lazy;
int main(){
	cin>>n;
	repn(i,n) scanf("%lld",&x[i]);
	repn(i,n) scanf("%lld",&t[i]);
	repn(i,n){
		que.push(x[i]+lazy);
		ll ans = 0;
		while(!que.empty() && que.top()-lazy <= t[i]){
			ans += que.top()-lazy;
			que.pop();
		}
		ans += t[i] * (ll)(que.size());
		lazy += t[i];
		printf("%lld ",ans);
	}
	puts("");
}