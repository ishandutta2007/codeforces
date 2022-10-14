/*
{By GWj
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int a[100000+20];
void solve(){
	R(n);
	vector<int> aa;
	rb(i,1,n)
		R(a[i]);
	LL rest=-(LL)(1e18);
	rb(i,1,n){
		if(a[i]==0){
			rest=0;
			continue;
		}
		aa.PB(a[i]);
	}
	n=aa.size();
	rb(i,1,n)
		a[i]=aa[i-1];
	if(n<5){
		cout<<0<<endl;
		return;
	}
	vector<int> pos,neg;
	rb(i,1,n)
		if(a[i]>0)
			pos.PB(a[i]);
		else neg.PB(-a[i]);
	sort(ALL(pos));
	sort(ALL(neg));
	bool ok=0;
	for(int i=1;i<=5;i+=2){
		if(pos.size()>=i&&neg.size()>=5-i){
			ok=1;
		}
	}
	if(!ok){
		LL res=-1;
		for(auto it:neg){
			pos.PB(it);
		}
		sort(ALL(pos));
		rep(i,5){
			res=res*pos[i];
		}
		check_max(rest,res);
	}
	else{
		reverse(ALL(neg));
		reverse(ALL(pos));
		for(int i=1;i<=5;i+=2){
			LL res=1;
			if(pos.size()>=i&&neg.size()>=5-i){
				rep(j,i){
					res=res*pos[j];
				}
				rep(j,5-i){
					res=res*neg[j];
				}
			}
			check_max(rest,res);
		}
	}
	cout<<rest<<endl;
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