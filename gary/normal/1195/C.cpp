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
int h1[100000+10],h2[100000+10];
LL dp[100000+10][4];
//1->pick up the first
//2->pick up the second
//3->pick up nobody
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&h1[i]);
	}
	rb(i,1,n){
		scanf("%d",&h2[i]);
	}
	rb(i,1,n){
		dp[i][3]=max(max(dp[i-1][1],dp[i-1][2]),dp[i-1][3]);
		dp[i][1]=max(dp[i-1][2],dp[i-1][3])+h1[i];
		dp[i][2]=max(dp[i-1][1],dp[i-1][3])+h2[i];
	}
	printf("%I64d",max(max(dp[n][3],dp[n][2]),dp[n][1]));
	return 0;
}