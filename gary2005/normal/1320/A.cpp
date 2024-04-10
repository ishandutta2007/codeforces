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
int b[200000+2];
int main(){
	fastio;
	set<pair<int,LL> >  dp;
	int n;
	cin>>n;
	rb(i,1,n)
		cin>>b[i];
	int add=0;
	rb(i,1,n){
		pair<int,LL> now;
		int need=b[i];
		now.FIR=need-add;
		set<pair<int,LL> >  ::IT ite=dp.lower_bound(II(need-add,-1));
//		cout<<need-add<<endl;
		if(ite!=dp.end()&&ite->FIR==need-add){
			now.SEC=b[i]+ite->SEC;
			dp.erase(ite);
		}
		else{
			now.SEC=b[i];
		}
		dp.insert(now);
		add++;
	}
	LL res=0;
	for(auto it:dp){
		res=max(res,it.SEC);
	}
	cout<<res;
	return 0;
}