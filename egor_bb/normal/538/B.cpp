#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;
const double eps = 1e-15;

using namespace std;



int n, a[10], c, ans[10], f;

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> n;
	a[0] = 1;
	for (int i = 1; i < 10; i++) a[i] = a[i - 1] * 10;
	while (n){
		f = max(f, n % 10);
		for (int i = 0; i < n % 10; i++){
			ans[i] += a[c];
		}
		c++;
		n /= 10;
	}
	cout << f << '\n';
	for (int i = 0; i < f; i++) cout << ans[i] << " ";


}