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
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<long long> vl;
typedef vector<vector<long long> > vll;
typedef vector<P> vp;
typedef vector<vector<P> > vpp;
class RMQ {
#define RMQ_MAX 1000000000000000000ll
public:
	RMQ(int n) {
		_n=1;
		while(_n<n) _n*=2;
		_dat.resize(2*_n-1);
		for(int i=0;i<2*_n-1;++i) _dat[i]=(RMQ_MAX);
	}
	int size() {
		return _n;
	}
	void update(int k,long long a) {
		k+=_n-1;
		_dat[k]=a;
		while(k>0) {
			k=(k-1)/2;
			_dat[k]=min(_dat[k*2+1],_dat[k*2+2]);
		}
	}
	// return the minimum number in [a,b)
	// external call should be written like query(a,b,0,0,_n)
	ll query(int a,int b,int k,int l,int r) {
		if(r<=a||b<=l) return RMQ_MAX;
		if(a<=l&&r<=b) return _dat[k];
		else {
			ll vl=query(a,b,k*2+1,l,(l+r)/2);
			ll vr=query(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}
private:
	int _n;
	vector<ll> _dat;
};

int main() {
	ios::sync_with_stdio(false);
	ll n,m,k;
	cin>>n>>m>>k;
	vector<pair<P,P> > fls(m);
	REP(i,m) cin>>fls[i].first.first>>fls[i].first.second>>fls[i].second.first>>fls[i].second.second;
	sort(ALL(fls));
	RMQ ret(1e7);
	ll comINF=0;
	ll retINF=0;
	ll comSUM=0;
	ll retSUM=0;
	vector<ll> comt(n+1,INF*INF);
	vector<ll> rett(n+1,INF*INF);
	ll res=INF*INF;
	for(ll i=m-1; i>=0; --i) {
		ll d=fls[i].first.first;
		ll f=fls[i].first.second;
		ll t=fls[i].second.first;
		ll c=fls[i].second.second;
		if(f==0) {
			if(rett[t]==INF*INF) {
				++retINF;
				rett[t]=c;
				retSUM+=c;
			} else {
				if(rett[t]>c) {
					retSUM-=rett[t];
					rett[t]=c;
					retSUM+=c;
				}
			}
			if(retINF==n) {
				ret.update(d,retSUM);
			}
		}
	}
	for(ll i=0; i<m; ++i) {
		ll d=fls[i].first.first;
		ll f=fls[i].first.second;
		ll t=fls[i].second.first;
		ll c=fls[i].second.second;
		if(t==0) {
			if(comt[f]==INF*INF) {
				++comINF;
				comt[f]=c;
				comSUM+=c;
			} else {
				if(comt[f]>c) {
					comSUM-=comt[f];
					comt[f]=c;
					comSUM+=c;
				}
			}
			if(comINF==n) {
				if(ret.query(d+1+k,1e7,0,0,ret.size())!=RMQ_MAX)res=min(res,comSUM+ret.query(d+1+k,ret.size(),0,0,ret.size()));
			}
		}
	}
	if(res!=INF*INF) cout<<res<<endl;
	else cout<<-1<<endl;
}