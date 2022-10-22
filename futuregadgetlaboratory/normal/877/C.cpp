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

int main() {
	int n;
	scanf("%d", &n);
	vector<int> ans;
	for(int i(2); i <= n; i += 2) 
		ans.push_back(i);
	for(int i(1); i <= n; i += 2)
		ans.push_back(i);
	for(int i(2); i <= n; i += 2) 
		ans.push_back(i);
	cout << ans.size() << endl;
	for(int i(0); i < (int)ans.size(); i++)
		printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
}