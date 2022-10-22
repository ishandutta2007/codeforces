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
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

int a[MAXN];

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	multiset <int> s1, s2;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		s2.insert(a[i]);
	}

	for (int i = 0; i < n - 1; ++i){
		s2.erase(s2.find(a[i]));
		s1.insert(a[i]);

		int mx2 = *s2.rbegin();

		while (s1.size() && *s1.rbegin() >= mx2){
			int mx1 = *s1.rbegin();
			cout << mx1 << ' ';
			s1.erase(s1.find(mx1));
		}

		cout << '\n';
	}

	s1.insert(a[n - 1]);
	while (s1.size()){
		int mx1 = *s1.rbegin();
		cout << mx1 << ' ';
		s1.erase(s1.find(mx1));
	}

	cout << '\n';
	return 0;;
}