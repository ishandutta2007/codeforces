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
int cnt[300005];
ll C[2],ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		ll x; scanf("%lld",&x);
		cnt[i] = __builtin_popcountll(x);
		//cnt[i] %= 2;
	}
	C[0]++;
	int a = 0;
	ll ans = 0;
	for(int i=0;i<n;i++){
		a ^= (cnt[i]%2);
		ans += C[a];
		C[a]++;
	}
	for(int i=0;i<n;i++){
		int w = 0;
		int mx = 0;
		int sum = 0;
		for(int j=i;j>=max(0,i-130);j--){
			w ^= (cnt[j])%2;
			sum += cnt[j];
			mx = max(mx,cnt[j]);
			if(w == 0 && mx*2 > sum) ans--;
		}
	}
	cout<<ans<<endl;
}