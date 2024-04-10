#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "movetofront"

const int INF = int(1e9);
const int INFll = int(1e9) + 7;
const int SZ = 70;

using namespace std;

ll l = 1, r = 9, n, ans, k = 1;

int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	cin >> n;
	while (n > r){
		ans += k * (r - l + 1);
		l *= 10;
		r = r * 10 + 9;
		k++;
	}
	ans += (n - l + 1) * k;
	cout << ans << '\n';
}