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
vector<int> v;

int n;
string s[5000+1];


int main(){
	fastio;
	R(n);
	rb(i,1,n) R(s[i]),s[i]='!'+s[i];
	vector<int> v; 
	rb(i,1,n){
		int ok=0;
		// v[k]->v[k-1]->...v[0]
		while(ok<v.size()&&s[i][v[ok]]=='1'){
			ok++;
		}
		v.insert(v.begin()+ok,i);
		rb(j,ok,v.size()-1)
			if(s[v[ok]][v[j]]=='1'){
				cout<<v[j]<<" "<<v[ok+1]<<" "<<v[ok]<<endl;
				return 0;
			}
	}
	cout<<-1<<endl;
	return 0;
}