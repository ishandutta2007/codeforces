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
//LL dp[1001][1001][5];
LL res=4;
int main(){
//	dp[1][1][1]=dp[1][1][2]=dp[1][1][3]=dp[1][1][4]=1;
	int w,h;
	scanf("%d %d",&w,&h);
	rb(i,1,w-1){
		res*=2;
		res%=998244353 ; 
	}
	rb(i,1,h-1){
		res*=2;
		res%=998244353 ;
	}
	cout<<res<<endl;
	return 0;
}