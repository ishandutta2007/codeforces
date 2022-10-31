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


ll used[55], n, m, l = 0, r, ans[55], k = 1;



int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	cin >> n >> m;
	r = n - 1;
	ll num = (1ll << (n - 1));
	for (int i = 0; i < n; i++){
		if (m <= num / 2){
			ans[l++] = k++;
			num >>= 1;
		} else {
			ans[r--] = k++;
			num >>= 1;
			m -= num;
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
}