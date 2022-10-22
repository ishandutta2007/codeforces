#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>


using namespace std;


#define int long long
mt19937 rnd(rand());
int inf = 1e9;
int mod = 1e9 + 7;
int big_inf = 1e18;


struct lul{
	int x, y, cost;
	bool used;
};


bool check1(int x1, int y1, int x2, int y2){
	return (abs(x1 - x2) + abs(y1 - y2)) == 1;
}


bool check2(int x1, int y1, int x2, int y2){
	return (abs(x1 - x2) <= 2) || (abs(y1 - y2) <= 2);
}


bool check3(int x1, int y1, int x2, int y2){
	return (abs(x1 - x2) <= 1) || (abs(y1 - y2) <= 1);
}


signed main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	int x, y;
	vector <lul> good;
	int first_ind, last_ind;
	bool is_last_good = false;
	for (int i = 0; i < k; ++i){
		cin >> x >> y;

		lul new_elem;
		new_elem.x = x - 1;
		new_elem.y = y - 1;
		new_elem.cost = mod;
		new_elem.used = false;

		if (x == 1 && y == 1){
			first_ind = i;
			new_elem.cost = 0;
		}

		if (x == n && y == m){
			is_last_good = true;
			last_ind = i;
		}

		good.push_back(new_elem);
	}


	vector <int> q1 = { first_ind }, q2;
	int i1 = 0, i2 = 0;
	while (i1 < q1.size() || i2 < q2.size()){
		int ind;

		if (i1 < q1.size()){
			ind = q1[i1++];

			if (good[ind].used)
				continue;
		}
		else{
			ind = q2[i2++];

			if (good[ind].used)
				continue;
		}

			
		x = good[ind].x;
		y = good[ind].y;
		good[ind].used = true;
		for (int i = 0; i < k; ++i){
			if (good[ind].cost < good[i].cost && check1(x, y, good[i].x, good[i].y)){
				good[i].cost = good[ind].cost;
				q1.push_back(i);
			}
			else if (good[ind].cost + 1 < good[i].cost && check2(x, y, good[i].x, good[i].y)){
				good[i].cost = good[ind].cost + 1;
				q2.push_back(i);
			}
		}
	}

	int ans = mod;
	if (is_last_good)
		ans = good[last_ind].cost;

	for (int i = 0; i < k; ++i){
		if (check1(good[i].x, good[i].y, n - 1, m - 1) || check3(good[i].x, good[i].y, n - 1, m - 1))
			ans = min(ans, good[i].cost + 1);
	}


	if (ans >= mod){
		cout << -1;
	}
	else{
		cout << ans;
	}

	return 0;
}