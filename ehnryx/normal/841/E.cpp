#include <bits/stdc++.h>
using namespace std;

#define debug

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
const ll MOD = 1e9+7;
const int INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

vector<int> primes;
void init() {
	// primes
	bitset<40000> notprime;
	notprime[0] = notprime[1] = true;
	for (int i = 2; i < 200; i++) {
		if (notprime[i]) {
			for (int j = i*i; j < 40000; j+=i) 
				notprime[j] = true;
		}
	}
	for (int i = 0; i < 40000; i++) 
		if (notprime[i] == false)
			primes.push_back(i);
}

int nonsquare(int n) {
	int ans = 1;
	int lim = sqrt(n);
	for (int i = 0; primes[i] <= lim; i++) {
		if (n % primes[i] == 0) {
			int count = 0;
			while (n % primes[i] == 0) {
				n /= primes[i];
				count++;
			}
			if (count % 2 == 1)
				ans *= primes[i];
		}
	}
	if (n > 1) {
		ans *= n;
	}
	return ans;
}

The story of Easy_DP:

	init();

	int n;
	cin >> n;
	int arr[n];
	map<int,int> group;
	vector<int> count;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int res = nonsquare(arr[i]);
		if (!group.count(res)) {
			group.insert(pair<int,int>(res, count.size()));
			count.push_back(1);
		}
		else {
			count[group[res]]++;
		}
	}
	sort(count.begin(), count.end(), greater<int>());
	vector<int> num; 
	vector<int> begin; int start = 0;
	for (int i = 0; i < count.size(); i++) {
		for (int j = 0; j < count[i]; j++) {
			begin.push_back(start);
			num.push_back(i);
		}
		start += count[i];
	}
	
	// use num to do stuff
	// dp[i][j][k] := up to index i, j total splits, k current splits
	ll dp[2][n+2][n+2];
	memset(dp, 0, sizeof(dp));
	dp[1][0][0] = 1;
	for (int i = 1; i < n; i++) {
		if (num[i] != num[i-1]) {
			// new group
			// update dp
			for (int j = 0; j < i; j++) {
				for (int k = 1; k <= j; k++) {
					dp[i%2][j][0] += dp[i%2][j][k];
					dp[i%2][j][k] = 0;
				}
			}
		}
		for (int j = 0; j < i; j++) {
			for (int k = 0; k <= j; k++) {
				// insert between current or beside current
				dp[(i+1)%2][j+1][k+1] = (dp[(i+1)%2][j+1][k+1] + (dp[i%2][j][k]*(2*(i-begin[i])-k))%MOD)%MOD;
				// insert between previous
				if (j > 0) dp[(i+1)%2][j-1][k] = (dp[(i+1)%2][j-1][k] + (dp[i%2][j][k]*(j-k))%MOD)%MOD;
				// insert elsewhere
				dp[(i+1)%2][j][k] = (dp[(i+1)%2][j][k] + (dp[i%2][j][k]*(i+1-(2*(i-begin[i])-k+j-k)))%MOD)%MOD;
			}
		}
		memset(dp[i%2], 0, sizeof(dp[i%2]));
	}
	cout << dp[n%2][0][0] << endl;

The End