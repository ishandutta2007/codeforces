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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int val[100000+20],n,c,a[100000+20];LL dp[100000+20];
int main(){
	fastio;
	cin>>n>>c;
	rb(i,1,n)
		cin>>a[i];
	if(n<c){
		LL res=0;
		rb(i,1,n)
			res+=a[i];
		cout<<res<<endl;
	}
	else{
		LL res=0;
		rb(i,1,n)
			res+=a[i];
		set<mp> s;
		rb(i,1,c)
			s.insert(II(a[i],i));
		rb(i,1,n-c+1){
			val[i]=(*s.begin()).FIR;
			s.erase(II(a[i],i));
			if(i+c<=n)
			s.insert(II(a[i+c],i+c));
		}
		rb(i,1,c-1)
		{
			dp[i]=0;
		} 
		deque<pair<LL,int> > q;
		rb(i,1,c){
			if(i+c-1>n) break;
			dp[i+c-1]=val[i];
		}
		rb(i,c+c,n){
			while(!q.empty()&&q.back().FIR<=dp[i-c]) q.pop_back();
			q.PB(II(dp[i-c],i-c));
			while(q.front().SEC<=i-c-c) q.pop_front();
			dp[i]=q.front().FIR+val[i-c+1];
		}
		LL maxi=0;
//		cout<<dp[2]<<endl;
		rb(i,n-c+1,n){
			maxi=max(maxi,dp[i]); 
//			cout<<dp[i]<<" "<<i<<endl;
		}
		cout<<res-maxi<<endl;
	}
	return 0;
}