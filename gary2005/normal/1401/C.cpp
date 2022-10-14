/*
{

AuThOr Gwj
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int a[100000+20],is[100000+20];
int n;
void solve(){
	R(n);
	int mi=INF;
	rb(i,1,n)
		R(a[i]),mi=min(mi,a[i]),is[i]=0;
	vector<int> vv; 
	rb(i,1,n){
		if(a[i]%mi){
			is[i]=a[i];
		}
		else{
			vv.PB(a[i]);
		}
	}
	sort(ALL(vv));
	int now=1;
	for(auto it:vv){
		while(is[now]){
			now++;
		}
		is[now]=it;
	}
	rb(i,2,n){
		if(is[i]<is[i-1]){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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