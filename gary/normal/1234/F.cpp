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
int dp[2097152+10]; 
int main(){
	string s;
	cin>>s;
	int len=s.length();
	s='&'+s;
	rb(i,1,len) s[i]-='a'-1;
	rb(i,1,len)
	{
		int tot[22]={0};
		tot[s[i]]++;
		dp[1<<(s[i]-1)]=1;
		int tot1=1;
		int mask=1<<(s[i]-1);
		rb(j,i+1,len){
			if(tot[s[j]]) break;
			tot[s[j]]++;
			mask|=1<<(s[j]-1);
			dp[mask]=++tot1;
		}
	 } 
	rb(mask,0,(1<<20)-1){
		rb(j,1,20)
			if(mask&(1<<(j-1)))
				dp[mask]=max(dp[mask],dp[mask-(1<<(j-1))]);
	}
//	cout<<dp[1]<<endl;
	int res=0;
	rb(mask,0,(1<<20)-1){
		int from=(~mask)&((1<<20)-1);
//		cout<<(from&mask)<<endl;
//		dp[mask]+=dp[from];
//		cout<<mask<<" "<<dp[mask]<<" "<<res<<endl;
		res=max(dp[mask]+dp[from],res);
	}cout<<res<<endl;
	return 0;
}