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
const int size = 1000;
const long long mdl = 1000 * 1000 * 1000 + 7;

long long ans[size + 1][size + 1];
int nums[size];
long long fact[size * 2 + 1];
int n;
set <vector <int> > could;
long long cnk[size + 1][size + 1];

void rec(vector <int> &h1, vector <int> &h2) {
	could.insert(h1);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (h2[i] > 0 && h2[j] > 0) {
				swap(h1[i], h1[j]);
				h2[i]--;
				h2[j]--;
				rec(h1, h2);
				swap(h1[i], h1[j]);
				h2[j]++;
				h2[i]++;
			}
}


int main() {
	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	for (int i = 0; i <= size; i++) {
		cnk[i][0] = 1;
		cnk[i][i] = 1;
		for (int j = 1; j < i; j++)
			cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mdl;
	}

	scanf("%d", &n);
	int c[2];
	c[0] = c[1] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
		c[nums[i] - 1]++;
	}
	vector <int> h1, h2;
	for (int i = 0; i < n; i++) {
		h1.pb(i);
		h2.pb(nums[i]);
	}
	//rec(h1, h2);
	fact[0] = 1;
	for (int i = 1; i < 2 * size; i++)
		fact[i] = (fact[i - 1] * i) % mdl;
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) {
			if (j <= 2)
				ans[i][j] = fact[i + j];
			else {
				ans[i][j] = 0;
				long long d;
				for (int k = 0; k <= i; k++) {
					d = 0;
					d += ((ans[i - k][j - 1] * fact[k]) % mdl);
					d += ((ans[i - k][j - 2] * fact[k + 1]) % mdl) * (j - 1);
					//cerr << cnk[i][k] << endl;
					d = ((d % mdl) * cnk[i][k]) % mdl;
					//cout << i << ' ' << j << ' ' << k << ' ' << d << endl;
					ans[i][j] += d;
				}
				ans[i][j] %= mdl;
			}
		}  
	cout << ans[c[1]][c[0]] << endl;
	//cout << could.size() << endl;
	
	return 0;
}