#pragma comment (linker, "/STACK:1000000000")

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
 
typedef long long ll;
typedef unsigned long long ull;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const ll N = 100005;

#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define problem "test"
 
using namespace std;

int a[200005], n;

double calc (double x){
	double mn = 0, mx = 0, sum = 0, ans = 0;
	for (int i = 0; i < n; i++){
		sum += (a[i] - x);
		ans = max(abs(sum - mn), ans);
		ans = max(abs(sum - mx), ans);
		mn = min(mn, sum);
		mx = max(mx, sum);
	}
	return ans;
}

int main(){
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	cin >> n;
	cout.precision(12);
	for (int i = 0; i < n; i++) cin >> a[i];
	double l = -1e4, r = 1e4;
	for (int q = 0; q < 300; q++){
		double ml = l + (r - l) / 3., mr = l +  (r - l) * 2. / 3.;
		double al = calc(ml), ar = calc(mr);
		if (al > ar) l = ml;
		else r = mr;
//		cout << ml << " " << al << " " << mr << " " << ar << '\n';
	}
	cout << fixed << calc((l + r) / 2.) << '\n';

}