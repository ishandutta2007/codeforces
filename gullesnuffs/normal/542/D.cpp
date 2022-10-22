#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

bool comp[1000005];
map<ll, ll> S[2];

bool isPrime(ll x){
	if(!x)
		return 1;
	if(x == 1)
		return 0;
	for(ll i=2; i*i <= x; ++i)
		if(x%i == 0)
			return 0;
	return 1;
}

int main(){
	ll A;
	cin >> A;
	comp[1]=1;
	for(int i=2; i < 1000005; ++i){
		if(comp[i])
			continue;
		for(int j=i*2; j < 1000005; j += i)
			comp[j]=1;
	}
	bool read=0, write=1;
	S[write][1]=1;
	for(int i=2; i < 1000005; ++i){
		if(comp[i])
			continue;
		ll m=i;
		bool any=0;
		while(m <= A){
			if(A%(1+m) == 0){
				if(!any){
					read^=1;
					write^=1;
					S[write]=S[read];
				}
				any=1;
				for(auto it=S[read].begin(); it != S[read].end(); ++it){
					if((1+m) > A/(it->first))
						continue;
					ll newval=(1+m)*(it->first);
					if(A%newval)
						continue;
					S[write][newval] += it->second;
				}
			}
			m *= i;
		}
	}
	read^=1;
	write^=1;
	ll ans=S[read][A];
	for(auto it=S[read].begin(); it != S[read].end(); ++it){
		if(A/(it->first)-1 < 1000005 || !isPrime(A/(it->first)-1))
			continue;
		ans += it->second;
	}
	cout << ans << endl;
}