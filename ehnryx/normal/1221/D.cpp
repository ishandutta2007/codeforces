#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;

const char nl = '\n';
const ll INFLL = 1e18+1;

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	os<<"[ "; for(T it:v) { os<<it<<", "; }
	return os<<"]";
}

const int N = 3e5+1;
int a[N], b[N];
ll dp[N][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(13);

	int T;
	for(cin>>T;T--;) {
		int n;
		cin>>n;
		a[0] = -7;
		for(int i=1;i<=n;i++) {
			cin>>a[i]>>b[i];
		}
		memset(dp[0],0,sizeof dp[0]);
		for(int i=1;i<=n;i++) {
			for(int j=0;j<3;j++) {
				dp[i][j] = INFLL;
				for(int k=0;k<3;k++) {
					if(a[i]+j==a[i-1]+k) continue;
					dp[i][j] = min(dp[i][j], dp[i-1][k]+j*b[i]);
				}
			}
		}
		cout<<*min_element(dp[n],dp[n]+3)<<nl;
	}

	return 0;
}