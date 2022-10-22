#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


int inf = 1e9;
long long big_inf = 1e18;


bool comp(pair <int, int> a, pair <int, int> b){
	return min(a.first * 2, a.second) - min(a.first, a.second) > min(b.first * 2, b.second) - min(b.first, b.second);
}


int main(){
	ios_base::sync_with_stdio(false);
	int n, f;
	cin >> n >> f;
	vector <pair <int, int> > a(n);

	for (int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end(), comp);

	long long ans = 0;
	for (int i = 0; i < f; ++i){
		ans += min(a[i].first * 2, a[i].second);
	}

	for (int i = f; i < n; ++i){
		ans += min(a[i].first, a[i].second);
	}

	cout << ans;
	return 0;
}