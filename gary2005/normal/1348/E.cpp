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
bool dp[505][505];//consider the first i ,and used k(k%K=j) red berries
int c[505];
int N,K,a[505],b[505];
LL s1,s2;

int main(){
	fastio;
	cin>>N>>K;
	rb(i,1,N)
		cin>>a[i]>>b[i],s1+=a[i],s2+=b[i];
	dp[0][0]=1;
	rep(i,N){
		rep(j,K)
			c[j]=0,dp[i+1][j]=dp[i][j];
		if(a[i+1]+b[i+1]>=K)
		rep(j,K){
			if(!dp[i][j]) continue;
			int l,r;
			l=max(1,K-b[i+1]);
			r=min(K-1,a[i+1]);
//			cout<<i<<" "<<l<<" "<<r<<endl;
			if(l<=r){
				int St,Ed;
				St=j+l;
				Ed=j+r;
				St%=K;
				Ed%=K;
				c[St]++;
				if(Ed>=St){
					c[Ed+1]--;
				} 
				else{
					c[0]++;
					c[Ed+1]--;
				}
			}
		}
		rep(j,K)
		{
			if(j) c[j]+=c[j-1];
			dp[i+1][j]|=c[j];
		}
	}
	LL res=0;
	rep(j,K){
		if(!dp[N][j]) continue;
//		cout<<j<<endl;
		LL l1,l2;
		l1=s1,l2=s2;
		l1-=j;
		l2-=(K-j)%K;
		LL cur=bool(j)+(l1/K)+(l2/K);
		res=max(res,cur);
	}
	cout<<res<<endl;
	return 0;
}