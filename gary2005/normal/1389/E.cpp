/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int t;
signed main(){
	fastio;
	cin>>t;
	while(t--){
		int m,d,w;
		R2(m,d);
		R(w);
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		int z=d-1;
		z%=w;
		if(z==0){
			cout<<(LL)min(d,m)*(min(d,m)-1)/2<<endl;
			continue;
		}
		int best=z*w/__gcd(z,w)/z;
		if(best>=d||best>=m){
			cout<<0<<endl;
			continue;
		}
		int r=min(d,m);
		LL res=0;
		int fr=r%best;
		int can=r/best;
			if(fr)
			res+=fr*can;
			can--;
			if(can>0)
			res+=(can)*(can+1)/2*best;
		cout<<res<<endl;
	}
	return 0;
}