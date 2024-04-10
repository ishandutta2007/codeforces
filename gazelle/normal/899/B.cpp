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
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
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
	string s1="312831303130313130313031312831303130313130313031312831303130313130313031";
	string s2="312931303130313130313031312831303130313130313031312831303130313130313031";
	string s3="312831303130313130313031312931303130313130313031312831303130313130313031";
	string s4="312831303130313130313031312831303130313130313031312931303130313130313031";
	string t="";
	REP(i,n) t+=to_string(a[i]);
	for(ll i=0;i+2*n<=(ll)s1.size();i+=2) {
		if(s1.substr(i,2*n)==t) {
			cout<<"YES"<<endl;
			return 0;
		}
	}
	for(ll i=0;i+2*n<=(ll)s2.size();i+=2) {
		if(s2.substr(i,2*n)==t) {
			cout<<"YES"<<endl;
			return 0;
		}
	}
	for(ll i=0;i+2*n<=(ll)s3.size();i+=2) {
		if(s3.substr(i,2*n)==t) {
			cout<<"YES"<<endl;
			return 0;
		}
	}
	for(ll i=0;i+2*n<=(ll)s4.size();i+=2) {
		if(s4.substr(i,2*n)==t) {
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}