#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int a[5005], b[5005];
int n, m;

int gcd(int a, int b){
	return b?gcd(b, a%b):a;
}

int saved[5005];

int getScore(int x){
	int score=0;
	for(int i=0; i < m; ++i){
		while(x%b[i] == 0){
			score--;
			x/=b[i];	
		}	
	}
	for(int i=2; i*i <= x; ++i)
		while(x%i == 0){
			x/=i;
			++score;
		}
	if(x > 1)
		++score;
	return score;
}

int G[5005];
int sum[5005];
int dp[5005];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i){
		scanf("%d", a+i);
	}
	for(int i=0; i < m; ++i){
		scanf("%d", b+i);
	}
	sum[0]=0;
	for(int i=0; i < n; ++i)
		sum[i+1]=sum[i]+getScore(a[i]);
	G[0]=a[0];
	for(int i=1; i < n; ++i)
		G[i]=gcd(G[i-1], a[i]);
	G[n]=1;
	for(int i=0; i <= n; ++i)
		saved[i]=getScore(G[i]);
	dp[n]=0;
	int ans=0;
	for(int i=n-1; i >= 0; --i){
		dp[i]=-999999999;
		for(int j=i+1; j <= n; ++j){
			int change=(i+1)*(saved[i]-saved[j]);
			dp[i]=max(dp[i], dp[j]-change);
		}
		ans=max(ans, dp[i]);
	}
	ans += sum[n];
	printf("%d\n", ans);
	/*vector<int> divisors;
	for(int i=1; i*i <= a[0]; ++i)
		if(a[i]%i == 0){
			if(i*i < a[0])
				divisors.push_back(a[0]/i);
			divisors.push_back(i);
		}
	map<int, int> dp[2];
	bool read=0, write=1;
	for(int i=0; i < divisors.size(); ++i)
		dp[write][-divisors[i]]=0;
	for(int i=0; i < n; ++i){
		read^=1;
		write^=1;
		dp[write].clear();
		for(auto it=dp[read].begin(); it != dp[read].end(); ++it){
			int d=-it->first, val=it->second;
			if(a[i]%d){
			}
		}
	}*/
	return 0;
}