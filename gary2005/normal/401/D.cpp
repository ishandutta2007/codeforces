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
string n;
int m;
LL dp[1<<19][100];
int main(){
	fastio;
	cin>>n>>m;
	int len=n.length();
	rep(i,len){
		n[i]-='0';
	}
	dp[0][0]=1;
	rep(mask,1<<len){
		bool app[10]={0};
		rep(i,len){
			if(mask&(1<<i)) continue;
			if(mask==0&&n[i]==0) continue;
			if(!app[n[i]]){
				app[n[i]]=1;		
				rep(j,m){
					dp[mask+(1<<i)][((j*10)+n[i])%m]+=dp[mask][j];
				}
			}
		}
	}
	cout<<dp[(1<<len)-1][0]<<endl;
	return 0;
}