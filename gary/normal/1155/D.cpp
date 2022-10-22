/*
	*#*#*#* Author GaryMr *#*#*#*
	
	long long
	
	dp
	
	 >=0
	
	dpg
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,x;
long long dp[300001][2][2],a[300001],ans=0;
int main(){
	scanf("%d %d",&n,&x);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++){
		dp[i][0][0]=max(dp[i-1][0][0]+a[i]*x,max(dp[i-1][1][1]+a[i]*x,a[i]*x));
		dp[i][1][0]=max(a[i],max(dp[i-1][1][0]+a[i],dp[i-1][0][0]+a[i]));
		dp[i][1][1]=max(a[i],dp[i-1][1][1]+a[i]);
		ans=max(max(dp[i][0][0],ans),max(dp[i][1][0],dp[i][1][1]));
	}
	printf("%I64d\n",ans);
	return 0;
}