#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair

const long long mod=1e9+7;

int n;
long long a[5555], dp[5555], p2[5555];

int main() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	a[n]=1;
	while (a[0]%2==0) p2[0]++, a[0]/=2;
	for (int i=1; i<=n; i++) {
		dp[i]=i;
		while (a[i]%2==0) p2[i]++, a[i]/=2;
		if (a[i]>0) {
			for (int j=i-1; j>=0; j--) {
				if (a[j]%a[i]==0&&(p2[j]+i-j==p2[i]||p2[i]<i-j)) dp[i]=min(dp[i], dp[j]+i-j-1);
			}
		}
	}
	cout << dp[n];
	return 0;
}