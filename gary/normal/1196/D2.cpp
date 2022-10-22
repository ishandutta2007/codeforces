//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int dp[200000+10][3];
//from i-th position and start with 0->R ,1->G,2->B
char tab[3]={'R','G','B'};
inline void solve(){
	dp[1][0]=dp[1][1]=dp[1][2]=0;
	int res=INF;
	int n,k;
	scanf("%d %d",&n,&k);
	string s;
	cin>>s;
	int now=0;
	rb(i,1,k){
		now%=3;
		if(s[i-1]!=tab[now]){
			dp[1][0]++;
		}
		now++;
	}
	now=1;
	rb(i,1,k){
		now%=3;
		if(s[i-1]!=tab[now]){
			dp[1][1]++;
		}
		now++;
	}
	now=2;
	rb(i,1,k){
		now%=3;
		if(s[i-1]!=tab[now]){
			dp[1][2]++;
		}
		now++;
	}
	res=min(dp[1][0],min(dp[1][1],dp[1][2]));//out<<dp[1][0]<<" "<<dp[1][1]<<" "<<dp[1][2]<<endl;
	int ADD=(k-1)%3;
	rb(i,2,n-k+1){
		dp[i][0]=dp[i-1][2]-(s[i-2]!='B')+(s[i+k-2]!=tab[ADD]);
		dp[i][1]=dp[i-1][0]-(s[i-2]!='R')+(s[i+k-2]!=tab[(ADD+1)%3]);
		dp[i][2]=dp[i-1][1]-(s[i-2]!='G')+(s[i+k-2]!=tab[(ADD+2)%3]);
		res=min(min(res,dp[i][0]),min(dp[i][1],dp[i][2]));
	}
	printf("%d\n",res);
}
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		solve();
	}
	return 0;
}