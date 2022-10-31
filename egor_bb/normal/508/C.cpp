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


int m, t, r, ans = 0, cnt[1000], used[1000];

int main(){
  //  ifstream cin (problem".in");
//	ofstream cout (problem".out");
	cin >> m >> t >> r;
	if (t < r){
		cout << -1;
		return 0;
	}
	for (int i = 0; i < m; i++){
		int k;
		cin >> k;
		k += 400;
		ans += r - cnt[k];
		int f = k;
		while (cnt[k] != r){
			if (!used[f]){
				used[f] = 1;
				for (int q = f; q < f + t; q++){
					cnt[q]++;
				}
			}
			f--;
		}

	}
	cout << ans << '\n';
	return 0;
}