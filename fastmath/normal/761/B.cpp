#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n, l;
	cin >> n >> l;

	vector <int> a(n);
	vector <int> b(n);

	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	for (int i = 0; i < n; i++){
		cin >> b[i];
	}

	string ans = "NO";
	vector <int> new_a(n);
	vector <int> new_b(n);
	for (int k = 0; k < l; k++){
		for (int s = 0; s < l; s++){
			for (int i = 0; i < n; i++){
				new_a[i] = (k + a[i]) % l;
				new_b[i] = (s + b[i]) % l;
			}

			sort(new_a.begin(), new_a.end());
			sort(new_b.begin(), new_b.end());

			if (new_a == new_b){
				ans = "YES";
			}
		}
	}

	cout << ans;
	return 0;
}