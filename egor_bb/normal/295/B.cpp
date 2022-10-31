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

ll d[505][505], x[505], n, ans = 0;


int main(){
	//ifstream cin ("in.txt");
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> d[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> x[n - i - 1];
		x[n - i - 1]--;
	}
	vector <ll> qwe;
	qwe.resize(n, 0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				d[x[j]][x[k]] = min(d[x[j]][x[i]] + d[x[i]][x[k]], d[x[j]][x[k]]);
			}
		}
		for (int j = 0; j <= i; j++){
			for (int k = 0; k <= i; k++){
				qwe[i] += d[x[j]][x[k]];
			}
		}
	}
	for (int i = n - 1; i>=0; i--) cout << qwe[i] << " ";

	return 0;
}