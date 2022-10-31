#pragma comment (linker, "/STACK:100000000000")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e17 + 7)
#define sort stable_sort

using namespace std;




ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}

int d[305][305], n, k;
ll ans;


int main(){
//	ifstream cin ("in.txt");
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cin >> d[i][j];
			ans += d[i][j];
		}
	cin >> k;
	for (int q = 0; q < k; q++){
		int t1, t2, w;
		cin >> t1 >> t2 >> w;
		t1--; t2--;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				ans -= d[i][j];
				if (d[i][j] > d[i][t1] + w + d[t2][j]){
					d[i][j] = d[i][t1] + w + d[t2][j];
				}
				if (d[i][j] > d[i][t2] + w + d[j][t1]){
					d[i][j] = d[i][t2] + w + d[j][t1];
				}
				ans += d[i][j];
			}
		}

		cout << ans / 2 << " ";
	}

	return 0;
}