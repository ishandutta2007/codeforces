#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
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
int dp[100];
int main(){
	ios::sync_with_stdio(false);
	dp[0]=1;
	int n;
	cin>>n;
	if(n&1){
		cout<<0;
		return 0;
	}
	rb(i,1,n){
		if(i>=2)
		dp[i]=dp[i-2]*2;
	}
	cout<<dp[n];
	return 0;
}