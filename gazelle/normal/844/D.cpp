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
#include<complex>
#include<random>
#include<time.h>

#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8

#define REP(i, m) for(long long i = 0; i < m; ++i)
#define FOR(i, n, m) for(long long i = n; i < m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;


int main() {
	ios::sync_with_stdio(false);
	ll n,start,x;
	cin>>n>>start>>x;
	srand((unsigned int)time(NULL));
	ll dif=INF*INF;
	ll pos=-1;
	ll bn=-1,an=-1;
	REP(i,500) {
		ll npos=(((rand()+rand())%n)+n)%n+1;
		cout<<"? "<<npos<<endl;
		ll val, nex;
		cin>>val>>nex;
		--nex;
		if(val<=x&&x-val<dif) {
			dif=x-val;
			pos=npos;
			bn=val;
		}
	}
	ll ans=-1;
	if(bn==x) {
		ans=x;
	}
	ll nnpos=pos;
	REP(i,999) {
		if(ans!=-1) break;
		if(nnpos==-1) break;
		cout<<"? "<<nnpos<<endl;
		ll val,nex;
		cin>>val>>nex;
		an=val;
		if(an>=x&&bn<x) {
			ans=an;
			break;
		}
		bn=an;
		nnpos=nex;
	}
	if(ans==-1) {
		ll bn=-1,an=0;
		ll hogepos=start;
		REP(i,500) {
			if(hogepos==-1) break;
			if(ans!=-1) break;
			cout<<"? "<<hogepos<<endl;
			ll val,nex;
			cin>>val>>nex;
			an=val;
			if(bn<x&&an>=x) ans=an;
			hogepos=nex;
			bn=an;
		}
	}
	cout<<"! "<<ans<<endl;
}