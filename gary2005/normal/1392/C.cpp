/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int a[200000+20];
void solve(){
	R(n);
	rb(i,1,n)
		R(a[i]);
	LL res=0;
	int l=1;
	vector<mp> seg;
	rb(i,2,n){
		if(a[i]<a[i-1]){
			seg.PB(II(l,i-1));
			l=i;
		}
	}
	seg.PB(II(l,n));
	int maxi=0;
	bool fir=0;
	int rr;
	for(auto it:seg){
		if(fir){
			res+=a[rr]-a[it.FIR];
		}
		rr=it.SEC;
		fir=1;
	}
	cout<<res<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}