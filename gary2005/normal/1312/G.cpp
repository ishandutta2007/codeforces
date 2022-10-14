/*
AuThOr GaRyMr
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
char c[1000000+20];
vector<int> each[1000000+20];
int queries[1000000+20],dp[1000000+20];
bool ok[1000000+20];
bool cmp(int A,int B){
	return c[A]<c[B];
}
int cnt=0;
void dfs(int now,int mini,int prev){
	cnt+=ok[now];
	if(!now){
		dp[now]=0;
	}
	else{
		if(ok[now]){
			dp[now]=min(dp[prev]+1,mini+cnt);
		} 
		else{
			dp[now]=dp[prev]+1;
		}
	}
	int save=dp[now]-cnt+ok[now];
	for(auto it:each[now]){
		dfs(it,min(mini,save),now);
	}
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n){
		int  pi;
		cin>>pi>>c[i];
		each[pi].PB(i);
	}
	int k;
	cin>>k;
	rb(i,1,n){
		sort(ALL(each[i-1]),cmp);
	}
	rb(i,1,k){
		cin>>queries[i];
		ok[queries[i]]=1;
	}
	dfs(0,INF,-1);
	rb(i,1,k){
		cout<<dp[queries[i]]<<" ";
	}
	return 0;
}