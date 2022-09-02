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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll a[200005];
int main(){
	scanf("%d",&n);
	ll cur = 0; ll x = 1;
	for(int i=0;i<n/2;i++){
		scanf("%lld",&a[i*2+1]);
		//cur+?, cur+?+a[i] are square
		while(x<200000LL){
			ll y = x*x+a[i*2+1];
			ll t = floor(sqrt((double)(y)));
			for(ll e=max(0LL,t-3LL);e<=t+3LL;e++){
				if(e*e == y){
					a[i*2] = x*x-cur;
					cur = e*e;
					x = e+1;
					goto nxt;
				}
			}
			x++;
		}
		puts("No"); return 0;
		nxt:;
	}
	puts("Yes");
	for(int i=0;i<n;i++) printf("%lld\n",a[i]);
}