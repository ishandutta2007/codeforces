#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


int inf = pow(10, 9);
long long big_inf = pow(10, 18);


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> p(n), a(n), b(n);
	set <pair < int, int> > s1, s2, s3;

	for (int i = 0; i < n; ++i){
		cin >> p[i];
	}

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i){
		cin >> b[i];
	}

	for (int i = 0; i < n; ++i){
		if (a[i] == 1) s1.insert({ p[i], i });
		if (a[i] == 2) s2.insert({ p[i], i });
		if (a[i] == 3) s3.insert({ p[i], i });
		if (b[i] == 1) s1.insert({ p[i], i });
		if (b[i] == 2) s2.insert({ p[i], i });
		if (b[i] == 3) s3.insert({ p[i], i });
	}

	int m;
	cin >> m;
	int c;
	for (int i = 0; i < m; ++i){
		cin >> c;
		if (c == 1){
			if (s1.size() == 0){
				cout << -1 << " ";
			}
			else{
				cout << s1.begin()->first << " ";
				s2.erase({ s1.begin()->first, s1.begin()->second });
				s3.erase({ s1.begin()->first, s1.begin()->second });
				s1.erase(s1.begin());
			}
		}

		if (c == 2){
			if (s2.size() == 0){
				cout << -1 << " ";
			}
			else{
				cout << s2.begin()->first << " ";
				s1.erase({ s2.begin()->first, s2.begin()->second });
				s3.erase({ s2.begin()->first, s2.begin()->second });
				s2.erase(s2.begin());
			}
		}

		if (c == 3){
			if (s3.size() == 0){
				cout << -1 << " ";
			}
			else{
				cout << s3.begin()->first << " ";
				s2.erase({ s3.begin()->first, s3.begin()->second });
				s1.erase({ s3.begin()->first, s3.begin()->second });
				s3.erase(s3.begin());
			}
		}
	}


	return 0;
}