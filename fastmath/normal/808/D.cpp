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
vector <long long> tree;


void update(int v, int tl, int tr, int p, int val){
	if (tl == tr){
	  tree[v] = val;
	  return;
	}
	
	int m = int(tl + tr) / 2;
	if (p <= m){
	  update(v * 2, tl, m, p, val);
	}
	else{
	  update(v * 2 + 1, m + 1, tr, p, val);
	}
	
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}


long long get(int v, int tl, int tr, int l, int r){
	if (tl > r || tr < l){
		return 0;
	}

	if (tl >= l && tr <= r){
		return tree[v];
	}

	int m = (tl + tr) / 2;
	return get(v * 2, tl, m, l, r) + get(v * 2 + 1, m + 1, tr, l, r);
}


int main(){
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector <int> a(n);
	tree.resize(4 * n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		update(1, 0, n - 1, i, a[i]);
	}

	int l, r;
	string ans = "NO";
	for (int i = 0; i < n; ++i){
		update(1, 0, n - 1, i, 0);

		l = -1;
		r = n;
		while (l < r - 1){
			int m = (l + r) / 2;
			if (get(1, 0, n - 1, 0, m) + a[i] <= get(1, 0, n - 1, m + 1, n - 1)){
				l = m;
			}
			else{
				r = m;
			}
		}

		if (l >= 0 && get(1, 0, n - 1, 0, l) + a[i] == get(1, 0, n - 1, l + 1, n - 1)) ans = "YES";
		if (l == -1 && a[i] == get(1, 0, n - 1, 0, n - 1)) ans = "YES";
		
		l = -1;
		r = n;
		while (l < r - 1){
			int m = (l + r) / 2;
			if (get(1, 0, n - 1, 0, m) <= get(1, 0, n - 1, m + 1, n - 1) + a[i]){
				l = m;
			}
			else{
				r = m;
			}
		}

		if (l >= 0 && get(1, 0, n - 1, 0, l) == get(1, 0, n - 1, l + 1, n - 1) + a[i]) ans = "YES";

		update(1, 0, n - 1, i, a[i]);
	}


	cout << ans;
	return 0;
}