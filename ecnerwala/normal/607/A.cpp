#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 2e5;
int N;
pii beacons[MAXN];
int dp[MAXN];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> beacons[i].A >> beacons[i].B;
	}
	sort(beacons, beacons + N);
	int res = 0;
	for(int i = 0; i < N; i++) {
		int j = lower_bound(beacons, beacons + N, pii(beacons[i].A - beacons[i].B, 0)) - beacons;
		j--;
		if(j < 0) dp[i] = 1;
		else dp[i] = dp[j] + 1;
		res = max(res, dp[i]);
	}
	cout << N - res << '\n';
	return 0;
}