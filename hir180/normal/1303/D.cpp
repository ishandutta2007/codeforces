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

int t;
ll cnt[30];
ll sum;
int n;
void solve(){
	cin >> sum >> n;
	ll S = 0;
	memset(cnt,0,sizeof(cnt));
	rep(i,n){
		ll a; cin >> a; S += a;
		rep(j,30){
			if((1LL<<j) == a){
				cnt[j]++;
				break;
			}
		}
	}
	if(S < sum){
		puts("-1"); return ;
	}
	bool ex[62]={};
	rep(i,62) if(((sum>>i)&1LL)) ex[i] = 1;
	ll zan = 0, pre = 0;
	int ans = 0;
	rep(i,62){
		if(ex[i]) zan += (1LL<<i);
		pre += (1LL<<i) * cnt[i];
		while(zan > pre){
			for(int j=i+1;j<30;j++){
				if(cnt[j] > 0){
					cnt[j] --;
					cnt[i] += (1LL<<(j-i));
					ans += j-i;
					pre += (1LL<<j);
					break;
				}
			}
		}
	}
	cout << ans << endl;
}
int main(){
	cin>>t;
	while(t--) solve();
}