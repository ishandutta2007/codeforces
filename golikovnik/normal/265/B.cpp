#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> heights(n);
	for (int i = 0; i < n; ++i) cin >> heights[i];
	long long t = 0;
	int h = 0;
	for (int i = 0; i < n; ++i) {
		t += abs(heights[i] - h);
		h = heights[i];
		++t;
		if (i == n - 1) break;
		if (h <= heights[i+1]) {
			++t;
			continue;
		}
		t += abs(heights[i] - heights[i+1]);
		h = heights[i+1];
		++t;
	}       
	cout << t << endl;
	return 0;
}