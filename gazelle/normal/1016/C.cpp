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

ll n;
ll func(vector<ll>& a, vector<ll>& b) {
	RSQ A(n);
	REP(i,n) A.update(i,a[i]);
	RSQ B(n);
	REP(i,n) B.update(i,b[i]);
	vector<ll> acm(n,0);
	REP(i,n) {
		if(i%2) {
			acm[i]=acm[i-1]+(i*2)*b[i]+(i*2+1)*a[i];
		} else {
			if(i==0) acm[i]=b[i];
			else {
				acm[i]=acm[i-1]+(i*2)*a[i]+(i*2+1)*b[i];
			}
		}
	}
	ll ret=acm[n-1];
	ll sum1=0;
	ll sum2=0;
	for(ll i=n-1; i>=0; i--) {
		sum1=sum1+A.query(i+1,n)+B.query(i+1,n)+b[i]*(2*((n-1)-i)+1);
		sum2=sum2+A.query(i+1,n)+B.query(i+1,n)+a[i]*(2*((n-1)-i)+1);
		if(i==0) break;
		if(i%2==0) {
			ret=max(ret,sum1+2*i*(A.query(i,n)+B.query(i,n))+acm[i-1]);
		}
		else {
			ret=max(ret,sum2+2*i*(A.query(i,n)+B.query(i,n))+acm[i-1]);
		}
	}
	ret=max(ret,sum1);
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	vector<ll> b(n);
	REP(i,n) cin>>b[i];
	cout<<func(a,b)<<endl;
	return 0;
}