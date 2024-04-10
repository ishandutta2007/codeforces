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
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int dp[3000+10][4];
int n;
int s[3000+10];
int c[3000+10];
int cost=INF;
int main(){
	memset(dp,0x3f,sizeof(dp));
	scanf("%d",&n);
	rep(i,n+1){
		dp[i][0]=0;
	}
	rb(i,1,n){
		scanf("%d",&s[i]);
	}
	rb(i,1,n){
		scanf("%d",&c[i]);
	}
	rb(i,1,n){
		rb(j,1,3){
			rb(k,0,i-1){
				if(s[k]<s[i])
				dp[i][j]=min(dp[i][j],dp[k][j-1]+c[i]);
			}
		}
		cost=min(cost,dp[i][3]);
	}
	if(cost>300000000){
		puts("-1");
		return 0;
	}
	printf("%d\n",cost);
	return 0;
}