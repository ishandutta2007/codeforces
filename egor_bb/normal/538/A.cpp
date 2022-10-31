#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;
const double eps = 1e-15;

using namespace std;



string s, t = "CODEFORCES";

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".in");
	int l = 0, r = 10;
	cin >> s;
	if (s.size() < 10){
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < s.size(); i++){
		if (i >= 10 || s[i] != t[i]) break;
		l++;
	}
	for (int i = 1; i <= 10; i++){
		if (t[10 - i] != s[s.size() - i]) break;
		r--;
	}
	if (l >= r) {
		cout << "YES\n";
	}
	else cout << "NO\n";
}