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

ll gcd(ll a, ll b) {		// 
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll cntdiv(ll a) {
	ll ret=0;
	for(ll i=1; i*i<=a; i++) {
		if(a%i==0) {
			if(i*i!=a) ret+=2;
			else ret++;
		}
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	vector<ll> cnt(100010,0);
	FOR(i,1,100010) cnt[i]=cntdiv(i);
	vector<bool> ok((1<<9),false);
	REP(i,8) FOR(j,i,8) FOR(k,i,8) {
		bitset<3> bi1(i);
		bitset<3> bi2(j);
		bitset<3> bi3(k);
		bool f=false;
		if(bi1[0]&&bi2[1]&&bi3[2]) f=true;
		if(bi1[0]&&bi3[1]&&bi2[2]) f=true;
		if(bi2[0]&&bi1[1]&&bi3[2]) f=true;
		if(bi2[0]&&bi3[1]&&bi1[2]) f=true;
		if(bi3[0]&&bi1[1]&&bi2[2]) f=true;
		if(bi3[0]&&bi2[1]&&bi1[2]) f=true;
		ok[i+(j<<3)+(k<<6)]=f;
	}
	REP(roop,t) {
		ll a,b,c;
		cin>>a>>b>>c;
		ll ans=0;
		vector<ll> d(8);
		d[1]=cnt[a]-cnt[gcd(a,b)]-cnt[gcd(a,c)]+cnt[gcd(gcd(a,b),c)];
		d[2]=cnt[b]-cnt[gcd(b,c)]-cnt[gcd(b,a)]+cnt[gcd(gcd(a,b),c)];
		d[3]=cnt[gcd(a,b)]-cnt[gcd(gcd(a,b),c)];
		d[4]=cnt[c]-cnt[gcd(c,a)]-cnt[gcd(c,b)]+cnt[gcd(gcd(a,b),c)];
		d[5]=cnt[gcd(a,c)]-cnt[gcd(gcd(a,b),c)];
		d[6]=cnt[gcd(b,c)]-cnt[gcd(gcd(a,b),c)];
		d[7]=cnt[gcd(gcd(a,b),c)];
		REP(i,8) FOR(j,i,8) FOR(k,j,8) {
			if(d[i]==0||d[j]==0||d[k]==0) continue;
			if(!ok[i+(j<<3)+(k<<6)]) continue;
			if(i==j&&j==k) {
				ans+=(d[i]+3-1)*(d[i]+3-2)*(d[i]+3-3)/6;
			} else {
				if(i==j) {
					ans+=(d[i]+2-1)*(d[i]+2-2)/2*d[k];
				} else if(j==k) {
					ans+=(d[j]+2-1)*(d[j]+2-2)/2*d[i];
				} else if(k==i) {
					ans+=(d[k]+2-1)*(d[k]+2-2)/2*d[j];
				} else ans+=d[i]*d[j]*d[k];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}