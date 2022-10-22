#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <random>
#include <string>

using namespace std;


#define int long long
mt19937 rnd(rand());


signed main(){
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int ans = 0;
	for (int i = 0; i < n; ++i){
		while (a[i] > k * 2){
			++ans;
			k *= 2;
		}
		
		k = max(k, a[i]);
	}

	cout << ans;
	return 0;
}