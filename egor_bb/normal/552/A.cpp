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

ll a[105][105], n; 

int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	cin >> n;
	for (int i =0 ;i < n; i++){
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		for (int j = x; j <= xx; j++){
			for (int k = y; k <= yy; k++){
				a[j][k]++;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < 105; i++){
		for (int j = 0; j < 105; j++){
			ans+= a[i][j];
		}
	}
	cout << ans << '\n';
}