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
const LL INF=10000000000000000;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;LL a[200000+1];
int res[200000+1];
string s;
void solve(){
	cin>>n>>s;
	LL st=INF;
	LL ss=0;
	rb(i,2,n){
		if(s[i-2]=='>'){
			if(i==2) a[1]=ss;
			ss-=(LL)(n)*10000000ll;
			a[i]=ss;
		}
		else{
			if(i==2) a[1]=ss;
			a[i]=++ss;
		}
	}
	vector<pair<LL,int> > v;
	rb(i,1,n)
		v.PB(II(a[i],i));
	sort(ALL(v));
	rb(i,1,n){
		res[v[i-1].SEC]=i;
	}
	rb(i,1,n){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	st=INF;
	ss=-INF;
	rb(i,2,n){
		if(s[i-2]=='>'){
			if(i==2) a[1]=ss;
			a[i]=--ss;
		}
		else{
			if(i==2) a[1]=st;
			ss+=n+n;
			a[i]=++st;
		}
	}
	 v.clear();
	rb(i,1,n)
		v.PB(II(a[i],i));
	sort(ALL(v));
	rb(i,1,n){
		res[v[i-1].SEC]=i;
	}
	rb(i,1,n){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}