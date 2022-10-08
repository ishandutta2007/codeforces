#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

vector <int> h;

int main() {
	int n, k, d;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	h.clear();
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> d;
		if (d > 0)
			h.pb(d);
	}
	sort(h.rbegin(), h.rend());
	k = min(k, int(h.size()));
	while (k > 0 && k < h.size() && h[k] == h[k - 1])
		k++;
	cout << k << endl;

	return 0;
}