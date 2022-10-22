#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
	long long int INF = pow(10, 15);
	int n, k;
	cin >> n >> k;
	vector <long long int> powers;

	if (k == 1){
		powers = { 1 };
	}
	else if (k == -1){
		powers = { 1, -1 };
	}
	else{
		long long int p = 1;
		while (p <= INF){
			powers.push_back(p);
			p *= k;
		}
	}

	int new_elem;
	map <long long int, int> sums;
	sums[0] = 1;
	long long int ans = 0;
	long long int sum = 0;
	for (int i = 0; i < n; i++){
		cin >> new_elem;
		sum += new_elem;

		if (sums.find(sum) != sums.end()){
			sums[sum]++;
		}
		else{
			sums[sum] = 1;
		}

		for (int i = 0; i < powers.size(); ++i){
			if (sums.find(sum - powers[i]) != sums.end()){
				ans += sums[sum - powers[i]];
			}
		}
	}

	cout << ans;
	return 0;
}