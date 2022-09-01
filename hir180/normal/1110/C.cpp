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
ll ans[30];
int q;
int main(){
	for(int i=2;i<=25;i++){
		int val = (1<<i)-1;
		ans[i] = 1;
		for(ll j=2;j*j<=val;j++){
			if(val%j == 0){
				ans[i] = max(ans[i],1LL*val/j);
			}
		}
	}
	cin>>q;
	rep(i,q){
		int x; cin>>x;
		for(int j=2;j<=25;j++){
			if((1<<j)-1 == x){
				cout << ans[j] << endl;
				goto nxt;
			}
		}
		for(int j=2;j<=25;j++){
			if((1<<j) > x){
				cout << (1<<j)-1 << endl;
				break;
			}
		}
		nxt:;
	}
}