#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


long long inf = 1e9 + 7;
long long big_inf = pow(10, 18);


int main(){
	vector <long long> p(1000228);
	p[0] = 1;
	for (int i = 1; i < 1000228; ++i){
		p[i] = (p[i - 1] * 2) % inf;
	}

	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n = s.size();

	long long ans = 0;
	int beta = 0;
	while (beta < n && s[beta] == 'b'){
		++beta;
	}

	int alfa = 0;
	while (alfa < n && s[n - alfa - 1] == 'a'){
		alfa++;
	}

	string new_s = "";
	for (int i = beta; i <= n - alfa - 1; ++i){
		new_s += s[i];
	}


	int j = -1;
	vector <int> a;
	for (int i = 0; i < new_s.size(); ++i){
		if (i == 0 || new_s[i] != new_s[i - 1]){
			a.push_back(1);
			++j;
		}
		else{
			a[j]++;
		}
	}

	int m = a.size();
	for (int i = 0; i < m; i += 2){
		ans = (ans + a[i + 1] * (p[a[i]] - 1)) % inf;

		if (i + 2 < m) a[i + 2] += a[i];
	}

	cout << ans << "\n";
	return 0;
}