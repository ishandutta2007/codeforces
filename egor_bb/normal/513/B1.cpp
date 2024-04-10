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


ll used[55], n, m, l, r, ans[55];



int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	cin >> n >> m;
	r = n - 1;
	ll num = (1 << (n - 1));
	for (int i = 0; i < n; i++){
		if (m <= num / 2){
			for (int j = 1; j <= n; j++){
				if (!used[j]){
					used[j] = 1;
					ans[l++] = j;
					break;
				}
			}
			num >>= 1;
		} else {
			for (int j = 1; j <= n; j++){
				if (!used[j]){
					used[j] = 1;
					ans[r--] = j;
					break;
				}
			}
			num >>= 1;
			m -= num;
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
}