#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <deque>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cmath>
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int MOD = (1e6) + 3;

#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define problem ""

const int N = 105;

using namespace std;

int a, b;

int main(){
	srand(time(NULL));
//	ios_base::sync_with_stdio(0); 
//	cin.tie(0);
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	cin >> a >> b;
	cout << min(a, b) << " " << ( max(a, b) - min(a, b) )/ 2;
}