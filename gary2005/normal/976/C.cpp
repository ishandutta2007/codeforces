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
vector<pair<mp,int> > segments;
int n;
bool cmp(pair<mp,int> A,pair<mp,int> B){
	if(A.FIR.FIR!=B.FIR.FIR) return A.FIR.FIR<B.FIR.FIR;
	return A.FIR.SEC>B.FIR.SEC;
}
int main(){
	fastio;
	R(n);
//	n=299999;
	rb(i,1,n){
		int l,r;
		R2(l,r);
//		if(i==1) l=1,r=2;
//		else l=2,r=4;
		segments.PB(II(II(l,r),i));
	}
	sort(ALL(segments),cmp);
	mp maxi=II(-INF,-INF); 
	rep(i,n){
		if(maxi.FIR>=segments[i].FIR.SEC){
			cout<<segments[i].SEC<<" "<<maxi.SEC<<endl;
			return 0;
		}
		check_max(maxi,II(segments[i].FIR.SEC,segments[i].SEC));
//		cout<<i<<endl;
	} 
	cout<<-1<<" "<<-1<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/