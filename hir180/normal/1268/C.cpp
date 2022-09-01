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
const ll mod = 998244353;
int n,a[200005],pos[200005];
ll ans[200005];
ll rev[200005];
priority_queue<int>sm;
priority_queue<int,vector<int>,greater<int>>bg;
ll sums,sumb;

struct BIT
{
	int bit[200005];
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		for(int s=i;s<200005;s+=f(s)) bit[s]+=x;
	}
	int sum(int i)
	{
		int res=0;
		for(int s=i;s>0;s-=f(s)) res+=bit[s];
		return res;
	}
}kaede;

int main(){
	scanf("%d",&n);
	repn(i,n) {scanf("%d",&a[i]);pos[a[i]]=i;}
	repn(i,n){
		if(i%2 == 1){
			sm.push(pos[i]);
			sums+=pos[i];
		}
		else{
			bg.push(pos[i]);
			sumb+=pos[i];
		}
		int t = 0;
		while(sm.size()&&bg.size()&&sm.top()>bg.top()){
			t++; assert(t<=3);
			int a = sm.top(); sm.pop();
			int b = bg.top(); bg.pop();
			sm.push(b); bg.push(a);
			sums+=b-a;
			sumb+=a-b;
		}
		if(i%2 == 0) ans[i] = sumb-sums;
		else ans[i] = sumb-sums+1LL*sm.top();
		if(i%2 == 0) ans[i] -= 1LL*(i/2)*(i/2);
		else ans[i] -= 1LL*(i/2)*(i/2+1);
		rev[i] = rev[i-1] + i-1 - kaede.sum(pos[i]);
		kaede.add(pos[i],1);
	}
	
	
	repn(i,n) printf("%lld\n",ans[i]+rev[i]);
}