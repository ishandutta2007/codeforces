#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	ll maxi=0;
	REP(i,n) maxi=max(a[i],maxi);
	ll diff=-1;
	FOR(i,1,n) {
		if(a[i]==a[i-1]) {
			cout<<"NO"<<endl;
			return 0;
		}
		if(a[i]!=a[i-1]+1&&a[i]!=a[i-1]-1) {
			if(diff==-1) {
				diff=abs(a[i]-a[i-1]);
			} else if(abs(a[i]-a[i-1])!=diff) {
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	if(diff==-1) {
		cout<<"YES"<<endl;
		cout<<1000000000<<" "<<1<<endl;
		return 0;
	}
	ll tmp=maxi/diff+1;
	if(maxi%diff==0) tmp--;;
	if(tmp<=INF) {
		REP(i,n-1) {
			if((a[i]%diff==0&&a[i+1]==a[i]+1)||((a[i]%diff==1&&a[i+1]==a[i]+-1))) {
				cout<<"NO"<<endl;
				return 0;
			}
		}
		cout<<"YES"<<endl;
		cout<<tmp<<" "<<diff<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}