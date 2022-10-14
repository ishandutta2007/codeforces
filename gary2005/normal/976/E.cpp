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
int n,a,b;
LL sum=0;
vector<pair<LL,LL> > v;
LL rest=0;
int hp[200000+20],d[200000+20];
int main(){
	fastio;
	cin>>n>>a>>b;
	rb(i,1,n)
		R2(hp[i],d[i]),sum+=d[i];
	if(b==0) cout<<sum<<endl;
	else{
		b=min(b,n);
		LL z=1;
		rb(i,1,a)
			z*=2;
		rb(i,1,n)
			v.PB(II(hp[i]-d[i],z*hp[i]-d[i]));
		sort(ALL(v));
		reverse(ALL(v));
		rest=sum;
		LL sumsum=0;
		rep(i,b)
		{
			if(v[i].FIR>0){
				sumsum+=v[i].FIR;
			}	
			else break;
		}
		rest=sum+sumsum;
		rep(i,b){
			check_max(rest,sum+sumsum-max(0ll,v[i].FIR)+max(0ll,v[i].SEC));
		}
		sumsum-=max(0ll,v[b-1].FIR); 
		rep(i,n)
			if(i>=b)
				 check_max(rest,sum+sumsum+max(0ll,v[i].SEC));
		cout<<rest<<endl;
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/