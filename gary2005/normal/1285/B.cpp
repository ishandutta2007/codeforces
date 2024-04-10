/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a_[100000+10];
void solve(){
	int n;
	LL a,b;
	a=b=0;
	cin>>n;
	LL c=-1;
	rb(i,1,n)
		{
			int ai;
			cin>>ai;
			a_[i]=ai;
			a+=ai;
		}
	bool ok=1;
	b=0;
	rb(i,2,n){
		b+=a_[i];
		if(b<0) b=0;
		c=max(b,c);
	}
	ok=ok&(c<a);
	b=0;
	rb(i,1,n-1){
		b+=a_[i];
		if(b<0) b=0;
		c=max(b,c);
	}
	ok=ok&(c<a);
	if(ok){
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}