	#include<bits/stdc++.h>
	using namespace std;
	#define N 5005
	#define M 37
	#define ull unsigned long long
	ull h[N],cf[N];
	int dp[N],n,a,b,i,j;
	char s[N];
	inline ull get(int l,int r){return h[r]-h[l]*cf[r-l];}
	bool check(int r,int len,ull ee){
		for(int i=0;i<=r-len;++i)
			if(get(i,i+len)==ee)return 1;
		return 0;
	}
	
	int main(){
		scanf("%d%d%d%s",&n,&a,&b,s+1);
		for(i=cf[0]=1;i<=n;++i)cf[i]=cf[i-1]*M,h[i]=h[i-1]*M+s[i];
		for(i=1;i<=n;++i){
			dp[i]=dp[i-1]+a;
			while(j<i){
				if(check(j,i-j,get(j,i)))break;
				++j;
			}
			dp[i]=min(dp[i],dp[j]+b);
		}
		cout<<dp[n];
	}