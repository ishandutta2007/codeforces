#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <deque>
#include <set>
#include <fstream>
#include <numeric>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#include <cassert>
#include <cmath>
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int N = int(3e6) + 10;
const int M = int(2e5) + 10;
const int MOD = int(1e5);

#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define forn(i, n) for (int i = 0; i < n; i++)
#define read(a) scanf("%d", &(a))
#define problem "test"

using namespace std;

int n, a[N], b[N];


int main(){
	srand(time(NULL));
//	ios_base::sync_with_stdio(0); 
//	cin.tie(0);
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	read(n);
	forn(i, n){
		int t; read(t);
		a[t]++;
	}
	for (int i = 0; i <= int(2e6); i++){
		b[i] += a[i];
		b[i + 1] += b[i] / 2;
		b[i] &= 1;
	}
	int ans = 0;
	for (int i = 0; i <= int(2e6); i++){
		ans += b[i];
	}
	printf("%d\n", ans);
}