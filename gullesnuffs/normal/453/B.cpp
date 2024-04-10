#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
int bit[65];
int dp[105][200000];
int parent[105][200000];

bool update(int pos, int bitmask){
	if(bit[pos]&bitmask)
		return false;
	return true;
}

void rec(int best, int pos){
	if(pos == 0)
		return;
	rec(best&(~bit[parent[pos][best]]), pos-1);
	printf("%d ", parent[pos][best]);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=2; i <= 60; ++i){
		bool prime=1;
		for(int j=2; j*j <= i; ++j)
			if(i%j == 0)
				prime=0;
		if(prime)
			primes.push_back(i);
	}
	for(int i=1; i <= 60; ++i){
		for(int j=0; j < primes.size(); ++j)
			if(i%primes[j] == 0)
				bit[i]|=(1<<j);
	}
	int ans=999999999;
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		for(int k=0; k < (1<<primes.size()); ++k)
			dp[i+1][k]=999999999;
		for(int k=0; k < (1<<primes.size()); ++k){
			for(int j=1; j <= 60; ++j){
				if(update(j, k)){
					int val=dp[i][k]+abs(j-a);
					if(val < dp[i+1][k|bit[j]]){
						dp[i+1][k|bit[j]]=val;
						parent[i+1][k|bit[j]]=j;
					}
				}
			}
		}
	}
	int best;
	for(int k=0; k < (1<<primes.size()); ++k){
		ans=min(ans, dp[n][k]);
		best=k;
	}
	rec(best, n);
	printf("\n");
}