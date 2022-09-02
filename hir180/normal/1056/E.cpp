#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
string s,t;
ll f[1000005],hashh[1000005];
ll p[5] = {31,37,41,43,47};
int a,b,n;
int main(){
	cin>>s>>t;
	n = t.size();
	rep(i,s.size()){
		if(s[i] == '0') a++;
		else b++;
	}
	srand((unsigned)time(NULL));
	int k = rand()%5;
	ll pr = p[k];
	ll cur = pr;
	rep(i,n){
		f[i] = cur;
		hashh[i] = f[i] * (t[i]-'a'+1) % mod;
		if(i) hashh[i] = (hashh[i]+hashh[i-1]) % mod;
		cur = cur*pr%mod;
	}
	//f[x] ... pr^(x+1)
	int ans = 0;
	for(int A=1;A<=n/a;A++){
		int zan = n-A*a;
		if(zan <= 0 || zan%b != 0) continue;
		ll B = zan/b;
		ll valA=-1,valB=-1;
		int nxt = 0;
		bool fail = 0;
		for(int j=0;j<s.size();j++){
			if(s[j] == '0'){
				ll hs = hashh[nxt+A-1];
				if(nxt) hs -= hashh[nxt-1];
				hs = (hs%mod*f[n-1-nxt]%mod+mod)%mod;
				nxt += A;
				if(valA == -1) valA = hs;
				else if(valA != hs) fail = 1;
			}
			else{
				ll hs = hashh[nxt+B-1];
				if(nxt) hs -= hashh[nxt-1];
				hs = (hs%mod*f[n-1-nxt]%mod+mod)%mod;
				nxt += B;
				if(valB == -1) valB = hs;
				else if(valB != hs) fail = 1;
			}
		}
		assert(nxt == n);
		if(A == B && valA == valB) continue;
		//cout<<A<<" "<<B<<" "<<fail<<endl;
		if(!fail) ans++;
	}
	cout<<ans<<endl;
}