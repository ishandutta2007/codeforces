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
int n,p,k;
vector<int> s[100000+2];
bool cmp(vector<int> v1,vector<int> v2){
	return v1[0]>v2[0];
}
LL dp[100000+5][1<<7];
int main(){
	fastio;
	cin>>n>>p>>k;
	rb(i,1,n){
		int ad;
		cin>>ad;
		s[i].PB(ad);
	}
	rb(i,1,n)
		rb(j,1,p)
		{
			int st;
			cin>>st; 
			s[i].PB(st); 
		}
//	cout<<s[1].size()<<endl;
	sort(s+1,s+1+n,cmp);
	dp[0][0]=0ll;
	memset(dp,-127,sizeof(dp));
	int c[1<<7]={0};
	rep(i,1<<7){
		int ma=i;
		while(ma){
			if(ma&1){
				c[i]++;
			}
			ma>>=1;
		}
	}
	dp[0][0]=0;
	rb(i,1,n){
		rep(mask,1<<p){
			if(dp[i-1][mask]<=dp[n+1][0])
				continue;
			if(k-(i-c[mask])>=0){
				dp[i][mask]=max(dp[i][mask],dp[i-1][mask]+s[i][0]);
			}dp[i][mask]=max(dp[i][mask],dp[i-1][mask]);
			rep(j,p){
				if(mask&(1<<j));
				else{
//					cout<<j<<endl;
					dp[i][mask|(1<<j)]=max(dp[i][mask|(1<<j)],dp[i-1][mask]+s[i][j+1]);
				}
			}
		}
	}
//	cout<<dp[2][0]<<endl;
	cout<<dp[n][(1<<p)-1]<<endl;
	return 0;
}