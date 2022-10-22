//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int cnt[22][22];
int dp[2000000+10];
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	rep(i,n){
		s[i]-='a'-1;
	}
	rep(i,n-1){
		cnt[s[i]][s[i+1]]++;
		cnt[s[i+1]][s[i]]++;
	}
	int upp_=1<<(m);
	upp_--;
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	rb(mask,1,upp_)
	{
		rb(i,1,m){
			if(mask&(1<<(i-1))){
				int n_mask=mask-(1<<(i-1));
				dp[mask]=min(dp[mask],dp[n_mask]);
			}
		}
		rb(j,1,m){
				rb(k,1,m){
					if(mask&(1<<(j-1)))
						{
							if(mask&(1<<(k-1)));
							else{
								dp[mask]+=cnt[j][k];
							}
						}
				}
		}
		
	}
	cout<<dp[upp_]<<endl;
	return 0;
}