#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> b(n);
	REP(i,n) cin>>b[i];
	if(n==1) {
		cout<<0<<endl;
		return 0;
	}
	ll ans=INF;
	for(ll i=-1; i<=1; i++) {
		for(ll j=-1; j<=1; j++) {
			vector<ll> tmp(n);
			REP(k,n) tmp[k]=b[k];
			tmp[0]+=i;
			tmp[1]+=j;
			ll diff=tmp[1]-tmp[0];
			ll buf=0;
			if(i!=0) buf++;
			if(j!=0) buf++;
			FOR(k,2,n) {
				if(tmp[k]-tmp[k-1]!=diff) {
					if(tmp[k]-tmp[k-1]==diff+1) {
						buf++;
						tmp[k]--;
					} else if(tmp[k]-tmp[k-1]==diff-1) {
						buf++;
						tmp[k]++;
					} else buf=INF;
				}
			}
			if(buf>=INF) continue;
			else ans=min(ans,buf);
		}
	}
	if(ans!=INF) cout<<ans<<endl;
	else cout<<-1<<endl;
}