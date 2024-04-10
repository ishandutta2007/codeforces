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
ll c,d,t[100005];
char ch[100005];

int main(){
	scanf("%d%lld%lld",&n,&c,&d);
	for(int i=0;i<n;i++) scanf("%lld %c",&t[i],&ch[i]);
	scanf("%lld",&t[n]); ch[n] = 'A';
	ll ans = d*n;
	ll val = 0;
	int last = n;
	for(int beg=n-1;beg>=0;beg--){
		ll cur = 1LL*beg*d;
		cur += c * (t[n]-t[beg]);
		if(ch[beg] == ch[beg+1]){
			val += min(d,c * (t[last]-t[beg+1]));
		}
		else{
			last = beg+1;
		}
		ans = min(ans,cur+val);
	}
	cout<<ans<<endl;
}