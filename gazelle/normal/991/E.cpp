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
#include<complex>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-7
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

vector<vector<ll>> memo(20,vector<ll>(20,-1));

ll nck(ll n, ll k) {
	if(memo[n][k]!=-1) return memo[n][k];
	if(n<=1) return memo[n][k]=1;
	if(k==n||k==0) return memo[n][k]=1;
	return memo[n][k]=nck(n-1,k)+nck(n-1,k-1);
}

vector<ll> cnt(10,0);

ll dfs(ll pos, vector<ll>& used) {
	if(pos==10) {
		ll ret=0;
		ll sum=0;
		REP(i,10) sum+=used[i];
		ll mul=1;
		ll tmp=0;
		REP(i,10) if(used[i]) {
			mul*=nck(sum-tmp,used[i]);
			tmp+=used[i];
		}
		ret+=mul;
		//DUMP(used);
		//cout<<ret<<endl;
		ll sum_lz=0;
		for(ll i=used[0]; i>0; i--) {
			ll buf=1;
			tmp=0;
			REP(j,10) {
				if(j==0) {
					buf*=nck(sum-i-tmp,used[0]-i);
					tmp+=used[0]-i;
				}
				else {
					buf*=nck(sum-i-tmp,used[j]);
					tmp+=used[j];
				}
			}
			//cout<<i<<" "<<buf<<endl;
			ret-=(buf-sum_lz);
			sum_lz=buf;
		}
		//cout<<ret<<endl;
		return ret;
	}
	if(cnt[pos]==0) return dfs(pos+1,used);
	ll ret=0;
	for(int i=1; i<=cnt[pos]; i++) {
		used[pos]=i;
		ret+=dfs(pos+1,used);
	}
	used[pos]=0;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string n;
	cin>>n;
	ll m=(ll)n.size();
	REP(i,m) cnt[n[i]-'0']++;
	vector<ll> used(10,0);
	cout<<dfs(0,used)<<endl;
}