#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <string>

#define INF 1000000007
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back

using namespace std;


	ll a[100005], b[100005], n, m, ansa, ansb, sa, sb;

int main(){
//	ifstream in ("input.txt");
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sa += a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		sb += b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	ansa = sb;
	for (int i = 0; i < n - 1; i++) ansa += min(a[i], sb);
	ansb = sa;
	for (int i = 0; i < m - 1; i++) ansb += min(b[i], sa);
	cout << min(ansa, ansb);
}