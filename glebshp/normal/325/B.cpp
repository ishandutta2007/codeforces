#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);


int main() {
    long long n;
	
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cin >> n;
	long long pw = 1;
	vector <long long> ans;
	while (pw <= n + 1) {
		long long lb = 1;
		long long rb = min(long long (sqrtl(2 * n * 1.0) + 10), (n + 1) / pw + 1);
		while (lb < rb) {
			long long mid = (lb + rb) / 2;
			long long val = mid * (mid - 1) / 2 + mid * (pw - 1);
			if (val < n)
				lb = mid + 1;
			else
				rb = mid;
		}
		long long mid = lb;
		long long val = mid * (mid - 1) / 2 + mid * (pw - 1);
		if (mid % 2 == 1 && val == n)
			ans.pb(lb * pw);
		pw *= 2;
	}

	if (ans.empty())
		cout << -1 << endl;
	else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < int(ans.size()); i++)
			cout << ans[i] << endl;
	}

    return 0;
}