#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <deque>
#include <cassert>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <string>

#define INF 1000000009
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define sort stable_sort
#define psi pair<string, int>
#define pll pair<ll, ll>
#define problem "test"


using namespace std;

char a[1005][1005], b[1005][1005];
int w, h;

int main(){
//	ifstream cin (problem".in");
	cin >> w >> h;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin >> a[j][i];
		}
	}
	for (int i = 0; i < w; i++){
		for (int j = 0; j < h; j++){
			b[2 * i][2 * j] = b[2 * i + 1][2 * j] = b[2 * i][2 * j + 1] = b[2 * i + 1][2 * j + 1] = a[i][j];
		}
	}
	for (int i = 0; i < 2 * w; i++){
		for (int j = 0; j < 2 * h; j++){
			cout << b[i][j];
		}
		cout << '\n';
	}
}