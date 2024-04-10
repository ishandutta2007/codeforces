#include <bits/stdc++.h>
using namespace std;
int main() {
	// ...
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<long long> heights;
	heights.push_back(0);
	for(int i = 0; i < n; ++i) {
		if(i % 2 == 0) {
			heights.push_back(heights.back() + a[i]);
		}
		else {
			heights.push_back(heights.back() - a[i]);
		}
	}
	n = heights.size(); // n++
	long long answer = 0;
	long long min_so_far = 0;
	vector<pair<long long, int>> valleys; // middles of M-shapes,  (height, count)
	valleys.emplace_back(LONG_LONG_MIN, 0);
	for(int i = 0; i < n - 1; ++i) {
		min_so_far = min(min_so_far, heights[i]);
		if(heights[i] > heights[i+1]) {
			long long high = heights[i];
			long long low = heights[i+1];
			long long extra = high - max(min_so_far, low);
			while(valleys.back().first > low) {
				// O(N) because only N objects are inserted so only N times you can pop
				answer += valleys.back().second;
				valleys.pop_back();
			}
			if(valleys.back().first == low) {
				answer += valleys.back().second;
			}
			if(low >= min_so_far) {
				if(valleys.back().first == low) {
					valleys.back().second++;
				}
				else {
					valleys.push_back({low, 1});
				}
			}
			answer += max(0LL, extra);
		}
	}
	cout << answer << "\n";
}