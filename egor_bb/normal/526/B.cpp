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
#define problem "test"
 
 
const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;
 
using namespace std;
 
int n, a[100000];
ll ans = 0;

int dfs(int v, int d){
	if (d == n) return a[v - 1];
	ll x, b;
	x = dfs(2 * v , d + 1);
	b = dfs(2 * v + 1, d + 1);
	ans += max(x, b) - min(x, b);
	return a[v - 1] + max(x, b);
}

int main(){
 // ifstream cin (problem".in");
//  ofstream cout(problem".out");
  cin >> n;
  for (int i = 1; i <= (1 << (n + 1)) - 2; i++){
	  cin >> a[i];
  }
  dfs(1, 0);
  cout << ans << '\n';



}