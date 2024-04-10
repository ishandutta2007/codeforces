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
string s;
int x;
//bool vis[100000+1];
bool rest[100000+1];
void solve(){
	R2(s,x);
//	memset(vis,0,sizeof(vis));
	memset(rest,1,sizeof(rest));
	rb(i,1,s.length()){
		if(s[i-1]-'0'==0){
			if(i>x){
			rest[i-x]=0;
			}
		if(i+x<=s.length()){
			rest[i+x]=0;
		}
		}
	}	
	rb(i,1,s.length()){
		if(s[i-1]=='1'){
			int ok=0;
			if(i>x){
				ok+=rest[i-x];
			}
			if(i+x<=s.length()){
				ok+=rest[i+x];
			}
			if(ok){
				
			}
			else{
				cout<<-1<<endl;
				return ;
			}
		}
	}
	rb(i,1,s.length()){
		cout<<rest[i];
	}
	cout<<endl;
}
int main(){
	fastio;
	int t;
	R(t);
	while(t--) solve();
	return 0;
}