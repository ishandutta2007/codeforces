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


int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <int> a(n);

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	int l, r, x;
	for (int i = 0; i < m; ++i){
		cin >> l >> r >> x;

		if (x < l || x > r){
			cout << "Yes\n";
		}
		else{
			int k = 0;
			for (int j = l - 1; j < r; ++j){
				if (a[j] < a[x - 1]){
					++k;
				}
			}

			if (k != (x - l)){
				cout << "No\n";
			}
			else{
				cout << "Yes\n";
			}
		}
	}


	return 0;
}