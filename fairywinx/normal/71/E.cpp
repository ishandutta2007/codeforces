// #define GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
#include <cmath>

#include <algorithm>
// #define int long long

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const string names[104] = {"MEOW","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl",
							"Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se",
							"Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb",
							"Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er",
							"Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At",
							"Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No",
							"Lr"};
map<string, int> who;

const int N = 20;
vector<int> ans[N];
int used1[N];
int used2[N];
int b[N];
int _;
bool can = false;

double get_time() {
	return (double) clock() / CLOCKS_PER_SEC;
}

bool rek_per(int kol, int k, vector<int> can) {
	if (kol == k - 1) {
		if (ans[kol].size())
			return true;
		int sum = 0;
		for(auto i: can)
			sum += i;
		if (sum != b[kol])
			return false;
		for(auto i: can) 
			ans[kol].push_back(i);
		return true;
	}
	if (ans[kol].size() != 0)
		return rek_per(kol + 1, k, can);
	if (get_time() > 1.4) {
		return false;
	}
	for(int mask = 0; mask < (1 << (int) (can.size())); ++mask) {
		if (get_time() > 1.4) {
			return false;
		}
		int kol_1 = __builtin_popcount(mask);
		if (kol_1 < 2 || _ * 2 - 2 > (can.size() - kol_1))
			continue;
		vector<int> _can;
		int sum = 0;
		for(int i = 0; i < can.size(); ++i) {
			if (mask & (1 << i)) {
				sum += can[i];
				ans[kol].push_back(can[i]);
			}
			else 
				_can.push_back(can[i]);
		}
		if (sum != b[kol])
			ans[kol].clear();
		else {
			int z = 0;
			for(int j = kol + 1; j < k; ++j) {
				if (!ans[j].size()) 
					z += b[j];
			}
			for(auto i: _can)
				z -= i;
			if (z == 0) {
				--_;
				bool o = rek_per(kol + 1, k, _can);
				++_;
				if (o)
					return true;
				else
					ans[kol].clear();
			}
		}
	}
	return false;
}


signed main() {
	setup();
	fill(used1, used1 + N, 0);
	fill(used2, used2 + N, 0);
	for(int i = 0; i < 104; ++i) 
		who[names[i]] = i;
			
	int n, k;
	cin >> n >> k;
	_ = k;
	int sum = 0;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		a[i] = who[s];
		sum += a[i];
		// cout << a[i] << ' ';
	}
	// cout << '\n';
	for(int i = 0; i < k; ++i) {
		string s;
		cin >> s;
		b[i] = who[s];
		sum -= b[i];
		// cout << b[i] << ' ';
	}
	if (sum != 0) {
		cout << "NO";
		return 0;
	}
	// cout << '\n';
	vector<int> can;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < k; ++j) {
			if (a[i] == b[j] && !used1[i] && !used2[j]) {
				--_;
				ans[j].push_back(a[i]);
				used1[i] = 1;
				used2[j] = 1;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		if (!used1[i])
			can.push_back(a[i]);
	}
	bool o = rek_per(0, k, can);
	if (!o) 
		cout << "NO\n";
	else {
		int kol = 0;
		for(int i = 0; i < k; ++i) {
			kol += ans[i].size();
		}
		if (kol == n) {
			cout << "YES\n";
			for(int j = 0; j < k; ++j) {
				for(int i = 0; i + 1 < ans[j].size(); ++i) 
					cout << names[ans[j][i]] << '+';
				cout << names[ans[j].back()] << "->";
				cout << names[b[j]] << '\n';
			}
		}
	}


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}