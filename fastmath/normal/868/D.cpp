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

#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 207;
const int MX = 100;

struct str{
	set <int> s[MX + 1];
	string left, right;
	int len;
};

int to_int(string s){
	int res = 0;
	for (int i = 0; i < s.size(); ++i){
		if (s[s.size() - i - 1] == '1'){
			res += (1 << i);
		}
	}

	return res;
}

str merge(str l, str r){
	str res;
	res.len = min(1000000, l.len + r.len);

	if (l.len < MX){
		res.left = l.left + r.left;
	}
	else{
		res.left = l.left;
	}

	if (r.len < MX){
		res.right = l.right + r.right;
	}
	else{
		res.right = r.right;
	}

	for (int len = 1; len < MX; ++len){

		for (auto elem : l.s[len]){
			res.s[len].insert(elem);
		}

		for (auto elem : r.s[len]){
			res.s[len].insert(elem);
		}

		for (int lp = 1; lp < len; ++lp){
			int rp = len - lp;

			if (lp > l.right.size() || rp > r.left.size()) continue;

			string new_el = "";
			for (int i = l.right.size() - lp; i < l.right.size(); ++i){
				new_el += l.right[i];
			}

			for (int i = 0; i < rp; ++i){
				new_el += r.left[i];
			}

			res.s[len].insert(to_int(new_el));
		}

	}

	return res;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <str> a(n);
	string s;
	for (int i = 0; i < n; ++i){
		cin >> s;

		string left = "";
		for (int p = 0; p < min(MX, (int)s.size()); ++p){
			left += s[p];
		}

		string right = "";
		for (int p = max((ll)0, (ll)s.size() - MX); p < s.size(); ++p){
			right += s[p];
		}

		a[i].left = left;
		a[i].right = right;
		a[i].len = s.size();
		for (int l = 0; l < s.size(); ++l){
			string new_el = "";
			for (int r = l; r < min((int)s.size(), l + MX - 1); ++r){
				new_el += s[r];
				a[i].s[r - l + 1].insert(to_int(new_el));
			}
		}
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i){
		int p1, p2;
		cin >> p1 >> p2;
		a.push_back(merge(a[p1 - 1], a[p2 - 1]));

		for (int len = 1; len <= MX; ++len){
			if (a[a.size() - 1].s[len].size() < (1 << len)){
				cout << len - 1 << '\n';
				break;
			}
		}
	}

	return 0;;
}