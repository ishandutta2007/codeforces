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
int cnt[505];
ll bin[505];
int main(){
	cin >> n;
	rep(i,n){
		int a; cin>>a;
		if(a != -1) cnt[a]++;
	}
	bin[0] = 1;
	for(int i=1;i<505;i++) bin[i] = bin[i-1]*2LL%mod;
	ll ans = bin[n-1]-1;
	rep(i,505){
		ans -= bin[cnt[i]]-1;
	}
	cout << (ans%mod+mod)%mod << endl;
}