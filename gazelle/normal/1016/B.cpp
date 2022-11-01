#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

class RSQ {
public:
	RSQ(int n) {
		_n=1;
		while(_n<n) _n*=2;
		_dat.resize(2*_n-1);
		for(int i=0;i<2*_n-1;++i) _dat[i]=0;
	}
	int size() {
		return _n;
	}
	void update(int k,long long a) {
		k+=_n-1;
		_dat[k]+=a;
		while(k>0) {
			k=(k-1)/2;
			_dat[k]+=a;
		}
	}
	// return the sum of [a,b)
	// external call should be written like query(a,b,0,0,_n)
	ll query(int a,int b,int k=0,int l=0,int r=-1) {
		if(r==-1) r=_n;
		if(r<=a||b<=l) return 0;
		if(a<=l&&r<=b) return _dat[k];
		else {
			ll vl=query(a,b,k*2+1,l,(l+r)/2);
			ll vr=query(a,b,k*2+2,(l+r)/2,r);
			return vl+vr;
		}
	}
private:
	int _n;
	vector<ll> _dat;
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,q;
	cin>>n>>m>>q;
	string s,t;
	cin>>s>>t;
	RSQ rsq(n);
	REP(i,n-m+1) {
		bool d=true;
		REP(j,m) {
			if(s[i+j]!=t[j]) d=false;
		}
		if(d) rsq.update(i,1);
	}
	REP(i,q) {
		ll l,r;
		cin>>l>>r;
		l--;
		r--;
		if(r-l+1<m) cout<<0<<endl;
		else {
			cout<<rsq.query(l,r-(m-1)+1)<<endl;
		}
	}
	return 0;
}