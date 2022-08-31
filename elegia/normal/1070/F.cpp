#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<int> W[4];
	for(int _ = 1; _ <= N; _++) {
		string s;
		int w;
		cin >> s >> w;
		
		W[(s[0] - '0') * 2 + s[1] - '0'].push_back(w);
	}
	for(int i = 0; i <= 3; i++)
		sort(W[i].begin(), W[i].end());
	
	long long ans = 0;
	
	while(! W[1].empty() && ! W[2].empty()) {
		ans += W[1].back() + W[2].back();
		W[1].pop_back();
		W[2].pop_back();
	}
	
	while(! W[1].empty()) {
		W[0].push_back(W[1].back());
		W[1].pop_back();
	}
	while(! W[2].empty()) {
		W[0].push_back(W[2].back());
		W[2].pop_back();
	}
	sort(W[0].begin(), W[0].end());
	
	while(! W[0].empty() && ! W[3].empty()) {
		ans += W[0].back() + W[3].back();
		W[0].pop_back();
		W[3].pop_back();
	}
	while(! W[3].empty()) {
		ans += W[3].back();
		W[3].pop_back();
	}
	
	cout << ans;
}