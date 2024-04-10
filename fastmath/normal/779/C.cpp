#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


bool comp(pair <int, int> a, pair<int, int> b){
	return a.first > b.first;
}


int main(){
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	vector <int> b(n);
	vector <pair< int, int > > r(n);

	for (int i = 0; i < n; i++){
		cin >> a[i];

	}

	for (int i = 0; i < n; i++){
		cin >> b[i];
	}

	for (int i = 0; i < n; i++){
		r[i].first = b[i] - a[i];
		r[i].second = i;
	}

	sort(r.begin(), r.end(), comp);

	int ans = 0;
	for (int i = 0; i < n; i++){
		int j = r[i].second;
		if (i < k || r[i].first > 0){
			ans += a[j];
		}
		else{
			ans += b[j];
		}
	}


	cout << ans;
	return 0;
}