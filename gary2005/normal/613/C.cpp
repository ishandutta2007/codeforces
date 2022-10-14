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
vector<int > cnt;
string cons(){
	string rest="";
	vector<pair<int,char> > v;
		pair<int,char> zz=II(0,'$');
		int cn=0;
		for(auto it:cnt){
			if(it&1){
				zz=II(it,'a'+cn);
			}
			else{
				v.PB(II(it/2,'a'+cn));
			}
			cn++;
		}
		for(auto it:v){
			rep(i,it.FIR){
				rest+=it.SEC;
			}
		}
		rep(j,zz.FIR){
			rest+=zz.SEC;
		}
		reverse(ALL(v));
		for(auto it:v){
			rep(i,it.FIR){
				rest+=it.SEC;
			}
		}
		return rest;
	
}
int main(){
	fastio;
	R(n);
	int cntt=0;
	rb(i,1,n){
		int cc;
		R(cc);
		cnt.PB(cc);
		cntt+=(cc&1);
	}
	if(n==1){
		cout<<cnt[0]<<endl;
		rb(i,1,cnt[0]){
			cout<<'a';
		}
		cout<<endl;
		return 0;
	}
	if(cntt>=2){
		cout<<0<<endl;
		rep(i,n)
		{
			rep(j,cnt[i]){
				cout<<char('a'+i);
			}
		}
		return 0;
	}
	int ggc=cnt[0];
	for(auto it:cnt)
		ggc=__gcd(ggc,it);
	vector<int> facts;
	for(int i=1;i*i<=ggc;i++){
		if(ggc%i==0){
			facts.PB(i);
			facts.PB(ggc/i);
		}
	}
	sort(ALL(facts));
	reverse(ALL(facts));
	pair<int,string> rest=II(0,"");
	for(auto it:facts)
	{
		int ccc=0;
		for(auto itt:cnt){
			ccc+=(itt/it)&1;
		}	
		if(ccc<=1){
			rep(i,n)
				cnt[i]/=it;
			string ss = cons();
			string s="";
			rb(i,1,it){
				s+=ss;
			}
			check_max(rest,II(it+(ccc==0)*it,s));
		}
	}
	cout<<rest.FIR<<endl<<rest.SEC<<endl;
	return 0;
}