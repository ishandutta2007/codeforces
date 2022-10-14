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
int a[101];
void solve(){
	int n;
	cin>>n;
	rb(i,1,n){
		R(a[i]);
	}
	vector<int> vv;
	rb(ii,1,n){
		rb(i,1,n){
			if(a[i]==vv.size()){
				vv.PB(a[i]);
				a[i]=-1;
				break;
			}
		}	
		if(vv.size()!=ii) break;
	}
	int rest=vv.size();
	vector<int> v2;
	rb(i,1,n){
		if(a[i]>=0){
			v2.PB(a[i]);
		}
	}
	sort(ALL(v2));
	v2.erase(unique(ALL(v2)),v2.end());
	rep(i,v2.size()){
		if(v2[i]!=i){
			break;
		}
		rest++;
	}
	cout<<rest<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		solve();
	}	
	return 0;
}