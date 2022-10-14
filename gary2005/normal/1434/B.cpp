/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int cnt=0;
int rest[100000+20];
set<int> unused;
int main(){
	fastio;
	cin>>n;
	stack<mp> sta;
	rb(i,1,n) unused.insert(i);
	rb(i,1,2*n){
		char c;
		cin>>c;
		if(c=='+'){
			cnt++;
		}	
		else{
			int z;
			cin>>z;
			while(!sta.empty()&&sta.top().FIR<z){
				sta.pop();
			}
			int can=0;
			if(!sta.empty())
				can=sta.top().SEC; 
			auto ite=unused.upper_bound(can);
			if(ite==unused.end()){
				cout<<"NO"<<endl;
				return 0;
			}
			if(*ite>cnt){
				cout<<"NO"<<endl;
				return 0;
			}
			rest[*ite]=z;
			unused.erase(ite);
			sta.push(II(z,cnt));
		}	
	}	
	cout<<"YES"<<endl;
	rb(i,1,n) cout<<rest[i]<<' ';cout<<endl;
	return 0;
}
/** 
  *
  *
  *
  *
  **/