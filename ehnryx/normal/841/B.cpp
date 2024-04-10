#include <bits/stdc++.h>
using namespace std;

//#define debug

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

The story of WHY_DID_I_RESUBMIT__SUM_IS_UNNECESSARY:

	int a;
	int n;
	cin >> n;
	int count[2];
	count[0] = count[1] = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += a;
		count[a%2]++;
	}
	if (sum%2 == 1) cout << "First" << endl;
	else if (count[1] > 0) cout << "First" << endl;
	else cout << "Second" << endl;

The End