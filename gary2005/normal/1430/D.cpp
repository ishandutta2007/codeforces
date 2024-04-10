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
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		vector<int> z;
		int las=0;
		int n;
		cin>>n;
		string s;
		cin>>s;
		s='*'+s;
		rb(i,1,n){
			if(s[i]!=s[i-1]){
				if(las){
					z.PB(i-las);
				}
				las=i;
			}
		}
		z.PB(n-las+1);
		int rest=0;
		int it=0,itt=0;
		while(it<z.size()){
			check_max(itt,it);
			while(itt<z.size()&&z[itt]==1) itt++;
			if(itt==z.size()){
				it+=2;
				rest++;
				continue;
			}
			else{
				z[itt]--;
				if(z[itt]==1) itt++;
				rest++;
			}
			it++;
		}
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