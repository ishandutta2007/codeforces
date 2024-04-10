#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

const long long MOD=1e9+7;

string s;
long long n, mult[20], sum[20];
string modif[111111];

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	for (int i=0; i<10; i++) mult[i]=10, sum[i]=i;
	cin >> s;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> modif[i];
	}
	for (int i=(int)n-1; i>=0; i--) {
		long long mult2=1, sum2=0, len=(int)modif[i].length();
		for (int j=3; j<len; j++) {
			mult2*=mult[modif[i][j]-'0'];
			mult2%=MOD;
			sum2*=mult[modif[i][j]-'0'];
			sum2+=sum[modif[i][j]-'0'];
			sum2%=MOD;
		}
		mult[modif[i][0]-'0']=mult2;
		sum[modif[i][0]-'0']=sum2;
	}
	long long res=0;
	for (int j=0; j<s.length(); j++) {
		res*=mult[s[j]-'0'];
		res+=sum[s[j]-'0'];
		res%=MOD;
	}
	cout << res;
	return 0;
}