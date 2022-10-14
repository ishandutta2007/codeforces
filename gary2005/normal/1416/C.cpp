/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
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
pair<pair<LL,LL>,int> dfs(vector<vector<int > > v,int is=30){
	if(is==-1) return II(II(0,0),0);
	vector<vector<int> > nv;
	pair<LL,LL> rest=II(0,0);
	pair<pair<LL,LL> ,int> re;
	rep(i,v.size()){
		vector<int> vv[2];
		int cnt[2]={0,0};
		reverse(ALL(v[i]));
		rep(j,v[i].size()){
			int ti=v[i][j];
			vv[(ti>>is)&1].PB(ti);
			if((ti>>is)&1){
				rest.FIR+=cnt[0];
			}
			else{
				rest.SEC+=cnt[1];
			}
			cnt[(ti>>is)&1]++;
		}
		reverse(ALL(vv[0]));
		reverse(ALL(vv[1]));
		if(vv[0].size())
		nv.PB(vv[0]);
		if(vv[1].size())
		nv.PB(vv[1]);
	}
	re=dfs(nv,is-1);
	LL sum=min(re.FIR.FIR,re.FIR.SEC);
	re.FIR.SEC=re.FIR.FIR=sum;
	re.FIR.SEC+=rest.SEC;
	re.FIR.FIR+=rest.FIR;
//	cout<<re.FIR.FIR<<" "<<re.FIR.SEC<<" "<<is<<" "<<v.size()<<endl;
	if(re.FIR.FIR<=re.FIR.SEC){
		
	} 
	else{
		re.SEC+=1<<is;
	}
	return re;
}
int main(){
	fastio;
	int n;
	R(n);
	vector<int> vv;
	rb(i,1,n){
		int ai;
		R(ai);
		 vv.PB(ai);
	}
	pair<pair<LL,LL>,int> rest=dfs(vector<vector<int> > (1,vv));
	cout<<min(rest.FIR.FIR,rest.FIR.SEC)<<" "<<rest.SEC<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/