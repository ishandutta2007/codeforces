#include <iostream>
#include <cstdio>

#include <utility>
#include <algorithm>

using namespace std;

const int MAX_A = 2020;
const int MAX_M = 2020;
const int MAX_N = (1 + MAX_A)/2;
const int INF = 1010000000;

int A, N, M;

bool rain[MAX_A];
pair<int, int> umbrellas[MAX_M];
int dp[MAX_M][2];

void fillrain(int s, int e) {
	for(int i = s;i < e;i++) {
		rain[i] = true;
	}
}

int main() {
	
	scanf("%d%d%d", &A, &N, &M);
	
	for(int i = 0;i < A;i++) {
		rain[i] = false;
	}
	
	for(int i = 0;i < N;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		fillrain(a, b);
	}
	
	umbrellas[0] = make_pair(-1, -1);
	for(int i = 1;i <= M;i++) {
		scanf("%d%d", &umbrellas[i].first, &umbrellas[i].second);
	}
	
	sort(umbrellas, umbrellas + (M+1));
	
	
	bool cur = true;
	
	for(int i = 0;i <= M+1;i++) {
		dp[i][cur] = INF;
	}
	
	dp[0][cur] = 0;
	dp[M+1][cur] = 0;
	
	int uctr = 1;
	for(int i = 0;i < A;i++) {
		
		while(uctr <= M && umbrellas[uctr].first == i) {
			dp[uctr][cur] = dp[M+1][cur];
			
			uctr++;
		}
		
		bool israining = rain[i];
		
		dp[M+1][!cur] = INF;
		
		for(int j = 1;j <= M;j++) {
			
			if(dp[j][cur] < INF)
				dp[j][!cur] = dp[j][cur] + umbrellas[j].second;
			else
				dp[j][!cur] = INF;
			
			if(dp[j][!cur] < dp[M+1][!cur])
				dp[M+1][!cur] = dp[j][!cur];
			
		}
		
		if(!israining) {
			
			dp[0][!cur] = min(dp[0][cur], dp[M+1][cur]);
			
		} else {
			dp[0][!cur] = INF;
		}
		if (dp[0][!cur] < dp[M+1][!cur])
			dp[M+1][!cur] = dp[0][!cur];
		
		cur = !cur;
		
	}
	
	int ans = dp[M+1][cur];
	if(ans >= INF) {
		ans = -1;
	}
	
	printf("%d\n", ans);
	
	return 0;
}