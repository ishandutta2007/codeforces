#pragma comment (linker, "/STACK:100000000000")
  
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <cassert>
#include <stack>
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
#define problem "test"
#define sc second
#define sort stable_sort
const int INF = (1e9 + 7);
const ll INFll = (1e18 + 7);
const int N = 300;
const int NM = 100000;
using namespace std;


int a[1005][1005], b[1005][1005], n, m, k;

int main(){
  //  ifstream cin (problem".in");
//	ofstream cout (problem".out");
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++){
		int l, r;
		cin >> l >> r;
		if (!b[l][r]) {
			b[l][r]++;
			a[l][r]++;
			a[l - 1][r]++;
			a[l][r - 1]++;
			a[l - 1][r - 1]++;
			if (a[l][r] == 4 || a[l - 1][r] == 4 || a[l - 1][r - 1] == 4 || a[l][r - 1] == 4){
				cout <<i + 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}