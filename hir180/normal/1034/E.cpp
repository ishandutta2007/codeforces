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

int n;
char a[(1<<21)+5];
char b[(1<<21)+5];
ll val[(1<<21)];
ll val2[(1<<21)];
ll ans[(1<<21)];

int main(){
	scanf("%d",&n);
	scanf("%s",&a);
	scanf("%s",&b);
	for(int i=0;i<(1<<n);i++){
		ll x = a[i]-'0';
		rep(j,__builtin_popcount(i)) x = x*4LL%(1LL<<50);
		val[i] = x;
	}
	for(int i=0;i<(1<<n);i++){
		ll x = b[i]-'0';
		rep(j,__builtin_popcount(i)) x = x*4LL%(1LL<<50);
		val2[i] = x;
	}
	//cnt[j]... j no submask
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++){
			if(((j>>i)&1)){
				val[j] += val[j^(1<<i)];
				val2[j] += val2[j^(1<<i)];
				if(val[i] >= (1LL<<50)) val[i] -= (1LL<<50);
				if(val2[i] >= (1LL<<50)) val2[i] -= (1LL<<50);
			}
		}
	}
	for(int i=0;i<(1<<n);i++) ans[i] = (val[i]*val2[i])%(1LL<<50);
	for(int i=0;i<(1<<n);i++) if(ans[i] < 0) ans[i] += (1LL<<50);
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++){
			if(((j>>i)&1)){
				ans[j] -= ans[j^(1<<i)];
				if(ans[j] < 0) ans[j] += (1LL<<50);
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		int x = __builtin_popcount(i);
		//mod 4^(x+1)
		rep(j,x) ans[i] /= 4LL;
		printf("%lld",(ans[i]&3));
	}
}