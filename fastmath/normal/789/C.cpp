#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


#define ll long long;
int inf = pow(10, 9);
long long int big_inf = pow(10, 18);


int main(){
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	vector <int> r1(n - 1);
	vector <int> r2(n - 1);

	long long int ans = 0;
	long long int min_pref1 = 0;
	long long int min_pref2 = 0;
	long long int pref1 = 0;
	long long int pref2 = 0;
	for (int i = 0; i < n - 1; ++i){
		r1[i] = abs(a[i] - a[i + 1]) * pow(-1, i);	
		r2[i] = -r1[i];

		pref1 += r1[i];
		pref2 += r2[i];

		min_pref1 = min(min_pref1, pref1);
		min_pref2 = min(min_pref2, pref2);

		ans = max(ans, pref1 - min_pref1);
		ans = max(ans, pref2 - min_pref2);
	}

	cout << ans;
	return 0;
}