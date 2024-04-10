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
ll n,m,k;
int main(){
	cin>>n>>m>>k;
	ll x = 2*n*m;
	if(x%k != 0){
		puts("NO");
		return 0;
	}
	vector<ll>vec,vec2;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			vec.pb(i);
			if(i*i != n) vec.pb(n/i);
		}
	}
	for(ll i=1;i*i<=m;i++){
		if(m%i==0){
			vec2.pb(i);
			if(i*i != m) vec2.pb(m/i);
		}
	}
	ll y = x/k; 
	for(int i=0;i<vec.size();i++){
		if(y%vec[i] == 0){
			ll a = vec[i];
			ll b = y/vec[i];
			if(a <= n && b <= m){
				puts("YES");
				puts("0 0");
				cout<<a<<" "<<0<<endl;
				cout<<0<<" "<<b<<endl;
				return 0;
			}
			if(a <= m && b <= n){
				puts("YES");
				puts("0 0");
				cout<<0<<" "<<a<<endl;
				cout<<b<<" "<<0<<endl;
				return 0;
			}
		}
	}
	for(int i=0;i<vec2.size();i++){
		if(y%vec2[i] == 0){
			ll a = y/vec2[i];
			ll b = vec2[i];
			if(a <= n && b <= m){
				puts("YES");
				puts("0 0");
				cout<<a<<" "<<0<<endl;
				cout<<0<<" "<<b<<endl;
				return 0;
			}
			if(a <= m && b <= n){
				puts("YES");
				puts("0 0");
				cout<<0<<" "<<a<<endl;
				cout<<b<<" "<<0<<endl;
				return 0;
			}
		}
	}
	assert(0);
}