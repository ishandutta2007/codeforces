#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define all(sdk) sdk.begin(),sdk.end()
#define mll map<ll,ll>
#define endl '\n'
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mit(m) for(map<ll,ll> :: iterator it=m.begin();it!=m.end();++it)
#define mp make_pair
#define hell 1000000007
#define vvll vector<vector<ll> >
#define vll vector<ll>
// #define int long long
#define sz (int)(3e3+5)



int ra[sz][sz];
vector<int> adjlist[sz];

int ro[sz][sz];

signed main(){
	fastio;
	int n,m,x,y;
	cin>>n>>m;
	rep(i,0,m){
		cin>>x>>y;
		adjlist[x].pb(y);
		ra[y][x]=1;
	}
	int cnt=0;
	rep(i,1,n+1){
		for(auto j:adjlist[i]){
			for(auto k:adjlist[j]){
				if(i==k) continue;
				ro[i][k]++;
			}
		}
	}
	rep(i,1,n+1){
		rep(k,1,n+1){
			cnt=(cnt+1LL*ro[i][k]*(ro[i][k]-1)/2)%hell;
		}
	}
	cout<<cnt;
}