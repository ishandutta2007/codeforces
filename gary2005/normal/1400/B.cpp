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

void solve(){
	int p,f,c1,c2,s,w;
	cin>>p>>f>>c1>>c2>>s>>w;
	if(s>w){
		swap(s,w);
		swap(c1,c2);
	}	
	int rest=0;
	int can=f/s;
	rb(i,0,c1){
		if(1ll*s*i>(LL)p) continue;
		int is=min(can,c1-i);
		rest=max(rest,is+i+min(c2,(f-is*s)/w+(p-s*i)/w));
	}
	cout<<rest<<endl;
}
int main(){
	fastio;
	int t;
	R(t);
	while(t--)solve();	
	return 0;
}