#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(ll i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<ll, int> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;

ll cuberoot(ll x){
	ll y=0;
	while(y*y*y <= x)
		++y;
	--y;
	return y;

}

pair<ll, ll> solve(ll m){
	if(!m)
		return make_pair(0, 0);
	ll ret=0;
	ll c=cuberoot(m);
	pair<ll, ll> r1=solve(m-c*c*c);
	pair<ll, ll> r2=c>1?solve(c*c*c-1-(c-1)*(c-1)*(c-1)):make_pair(-1LL, -1LL);
	if(r1.first >= r2.first){
		return make_pair(r1.first+1, r1.second+c*c*c);
	}
	else{
		return make_pair(r2.first+1, r2.second+(c-1)*(c-1)*(c-1));
	}
}

int main(){
	ll m;
	cin >> m;
	pair<ll, ll> ans=solve(m);
	cout << ans.first << " " << ans.second << endl;
}