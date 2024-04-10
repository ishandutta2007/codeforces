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


bool check(int i){
	int c = 0;
	while (i){
		if (i % 10) ++c;
		if (c > 1) return false;
		i /= 10;
	}

	return true;
}


int main(){
	ios_base::sync_with_stdio(false);

	int n, w;
	cin >> n >> w;

	vector <pair <int, int> > a(n);
	int s = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i].first;
		a[i].second = i;
		s += (a[i].first + 1) / 2;
	}

	sort(a.begin(), a.end());
	
	if (s > w){
		cout << -1;
	}
	else{
		vector <pair <int, int > > ans(n);
		bool f = false;

		for (int i = 0; i < 100; ++i){
			int d = w - s;
			for (int j = 0; j < n; ++j){
				ans[j] = { (a[j].first + 1) / 2, a[j].second };
			}

			for (int j = n - 1; j >= 0; --j){
				int can = min(i, a[j].first - (a[j].first + 1) / 2);
				if (d <= can){
					ans[j].first += d;
					f = true;
					break;
				}

				ans[j].first += can;
				d -= can;
			}

			if (f) break;
		}

		if (!f){
			cout << -1;
		}
		else{
			vector <int> ans1(n);
			for (int i = 0; i < n; ++i){
				ans1[ans[i].second] = ans[i].first;
			}

			for (int i = 0; i < n; ++i){
				cout << ans1[i] << " ";
			}
		}
	}


	return 0;
}