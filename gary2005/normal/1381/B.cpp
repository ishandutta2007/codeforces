/*
AuThOr Gwj
*/
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define get(a) cin>>a
#define get2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
bool dp[4004][2002];
int a[4004];
void solve(){
	memset(dp,0,sizeof(dp));
	int n;
	cin>>n;
	n<<=1;
	rb(i,1,n){
		cin>>a[i];
	}
	vector<int> v;
	dp[0][0]=1;
	int st=1;
	int maxi=a[1];
	rb(i,2,n){
		if(a[i]>maxi){
			v.PB(i-st);
			st=i;
		} 
		maxi=max(a[i],maxi);
	}
	v.PB(n-st+1);
	rb(i,1,v.size()){
		rb(j,0,n/2){
			dp[i][j]|=(j>=v[i-1]? dp[i-1][j-v[i-1]]:0)|dp[i-1][j];
		}
	}
	if(dp[v.size()][n/2]){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
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