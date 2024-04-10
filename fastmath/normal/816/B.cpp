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

int n, k, q;

vector <int> pref_sum(200001), s(200001);


int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> q;
	vector <pair <int, int> > a;

	int l, r;
	for (int i = 0; i < n; ++i){
		cin >> l >> r;
		a.push_back({ l, 1 });
		a.push_back({ r + 1, -1 });
	}

	sort(a.begin(), a.end());
	int balance = 0;
	int j = 0;
	for (int i = 1; i <= 200000; ++i){
		if (i == 91){
			int lul = 1;
		}

		while (j < a.size() && a[j].first == i){
			balance += a[j].second;
			++j;
		}

		if (balance >= k){
			s[i] = 1;
		}
	}


	for (int i = 1; i <= 200000; ++i){
		pref_sum[i] = pref_sum[i - 1] + s[i];
	}

	for (int i = 0; i < q; ++i){
		cin >> l >> r;

		cout << pref_sum[r] - pref_sum[l - 1] << "\n";
	}


	return 0;
}