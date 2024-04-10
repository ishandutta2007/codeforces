#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_b"

const double pi = acos(-1.0);
const int size = 100;

vector <int> segs;

int f(vector <int> p) {
	int n = p.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int cur = p[i];
		for (int j = i; j < n; j++) {
			cur = min(cur, p[j]);
			sum += cur;
		}
	}

	return sum;
}

int ans[size];

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	int n;
	long long m;
	cin >> n >> m;

	long long pw = 1;
	for (int i = 1; i < n; i++)
		pw *= 2;
	
	int lb = 0;
	int rb = n - 1;
	for (int i = 1; i <= n; i++) {
   		pw /= 2;

		if (m <= pw) {
			ans[lb++] = i;
		} else {
			m -= pw;		
			ans[rb--] = i;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");	
/*	
	vector <pair <int, vector <int> > > perm;
	vector <int> p;
	for (int i = 0; i < n; i++)
		p.pb(i);
	do {
		perm.pb(mp(f(p), p));
	} while(next_permutation(p.begin(), p.end()));

	sort(perm.rbegin(), perm.rend());
	while (perm.back().fs < perm[0].fs)
		perm.pop_back();
	
	cout << perm.size() << ' ' << perm[0].fs << ' ' << perm.back().fs << endl;
	for (int i = 0; i < (int) perm.size(); i++) {
		for (int j = 0; j < n; j++)
			cout << perm[i].sc[j] << ' ';
		cout << endl;
	}
*/
	return 0;
}