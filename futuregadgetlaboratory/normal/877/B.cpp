#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
const int N = 300033;
const int LOG = 20;
const int MOD = 1e9 + 7;
typedef complex<double> Complex;
int s[N];
int main() {
	string st;
	cin >> st;
	int n(st.size());
	for(int i(1); i <= n; i++) {
		s[i] = s[i - 1] + (st[i - 1] == 'a');
	}
	int ans(0);
	for(int i(0); i <= n; i++) {
		for(int j(i); j <= n; j++) {
			ans = max(ans, s[i] + (j - i - (s[j] - s[i])) + s[n] - s[j]);
		}
	}
	cout << ans << endl;
}