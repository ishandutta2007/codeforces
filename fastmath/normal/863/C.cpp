#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

bool used[4][4];
int tmp1[4][4], tmp2[4][4];
pair <int, int> go[4][4];

int get_type(int a, int b){
	if (a == b){
		return 2;
	}

	if (a == 3 && b == 2){
		return 0;
	}

	if (a == 2 && b == 1){
		return 0;
	}

	if (a == 1 && b == 3){
		return 0;
	}

	return 1;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);

	int k, a, b;
	cin >> k >> a >> b;

	for (int i = 1; i <= 3; ++i){
		for (int j = 1; j <= 3; ++j){
			cin >> tmp1[i][j];
		}
	}

	for (int i = 1; i <= 3; ++i){
		for (int j = 1; j <= 3; ++j){
			cin >> tmp2[i][j];
		}
	}

	for (int i = 1; i <= 3; ++i){
		for (int j = 1; j <= 3; ++j){
			go[i][j] = { tmp1[i][j], tmp2[i][j] };
		}
	}

	pair <int, int> u = { a, b };
	vector <pair <int, int> > vert;
	while (!used[u.first][u.second]){
		used[u.first][u.second] = true;
		vert.push_back(u);
		u = go[u.first][u.second];
	}

	if (k <= vert.size()){
		int count0 = 0, count1 = 0;
		for (int i = 0; i < k; ++i){
			int type = get_type(vert[i].first, vert[i].second);
			if (type == 0){
				++count0;
			}
			else if (type == 1){
				++count1;
			}
		}

		cout << count0 << ' ' << count1 << '\n';
		return 0;
	}

	int p0 = 0;
	int p1 = 0;
	int f = 0;
	while (vert[f] != u){
		int type = get_type(vert[f].first, vert[f].second);

		if (type == 0){
			++p0;
		}
		else if (type == 1){
			++p1;
		}

		++f;
	}

	k -= f;
	vector <pair <int, int> > last;
	for (int i = f; i < vert.size(); ++i){
		last.push_back(vert[i]);
	}

	int len = last.size();
	int c = k / len;

	
	int count0 = 0, count1 = 0;
	for (int i = 0; i < len; ++i){
		int type = get_type(last[i].first, last[i].second);

		if (type == 0){
			++count0;
		}
		else if (type == 1){
			++count1;
		}
	}

	count0 *= c;
	count1 *= c;

	int ost = k % len;
	for (int i = 0; i < ost; ++i){
		int type = get_type(last[i].first, last[i].second);

		if (type == 0){
			++count0;
		}
		else if (type == 1){
			++count1;
		}
	}

	cout << count0 + p0 << ' ' << count1 + p1 << '\n';
	return 0;
}