#include <bits/stdc++.h>

#define INF 18446744073709551615ULL

using namespace std;
typedef unsigned long long ull;

ull a, b, dp[64][2], x , y;
vector <int> ba, bb;

ull sum(ull a, ull b) {
	if(a == INF || b == INF) return INF;
	return a + b;
}

int main() {
	cin >> a >> b;

	ull at = a;
	while(at) {
		ba.push_back(at % 2);
		at /= 2;
	} ba.resize(64);

	ull bt = b;
	while(bt) {
		bb.push_back(bt % 2);
		bt /= 2;
	} bb.resize(64);

	for(int i=0; i<64; i++)
		dp[i][0] = dp[i][1] = INF;

	if(ba[0] && bb[0])
		dp[0][0] = dp[0][1] = 0;

	if(!ba[0] && !bb[0]) {
		dp[0][0] = 0;
		dp[0][1] = 1;
	}

	ull mult = 2;
	for(int i=1; i<64; i++, mult *= 2) {
		if(!ba[i] && !bb[i]) {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = sum(dp[i-1][0], mult);
		}
		else if(!ba[i] && bb[i]) {
			dp[i][1] = dp[i-1][1];
		}
		else if(ba[i] && !bb[i]) {
			dp[i][0] = dp[i-1][1];
			dp[i][1] = sum(dp[i-1][1], mult);
		}
		else if(ba[i] && bb[i]) {
			dp[i][0] = dp[i-1][0];
		}
	}
	
	x = dp[63][0];
	if(x == INF || x >= a) printf("-1\n");
	else {
		y = a - x;
		printf("%llu %llu\n", x, y);	
	}

	return 0;
}

/*
   SOMA   XOR   CARRY
     0     0      0  => dp[i][0] = dp[i-1][0]; dp[i][1] = dp[i-1][0] + mult
     0     0      1  => -1
     0     1      0  => -1
     0     1      1  => dp[i][1] = dp[i-1][1];
     1     0      0  => -1
     1     0      1  => dp[i][0] = dp[i-1][1]; dp[i][1] = dp[i-1][1] + mult
     1     1      0  => dp[i][0] = dp[i-1][0];
     1     1      1  => -1
*/