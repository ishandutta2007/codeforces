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
#define taskname "problem_cc"

const double pi = acos(-1.0);
const int size = 200 * 1000;
int a1[size];
int a2[size];
int n;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	
	vector <pair <int, int> > vec;
	int d;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		vec.pb(mp(d, i));
	}

	if (n == 1) {
		printf("YES\n");
		printf("%d\n", vec[0].fs);
		printf("0\n");
		return 0;
	}
	if (n == 2) {
		printf("YES\n");
		printf("%d 0\n", vec[0].fs);
		printf("0 %d\n", vec[1].fs);
		return 0;
	}
	printf("YES\n");
	

	sort(vec.begin(), vec.end());
	int tr = (n + 2) / 3;
	for (int i = 0; i < tr; i++)
		a2[vec[i].sc] = vec[i].fs;
	for (int i = 0; i < tr; i++)
		a1[vec[tr + i].sc] = vec[tr + i].fs;
	for (int i = 0; i < n - 2 * tr; i++)
		a1[vec[tr * 2 + i].sc] = tr - i - 1;
	for (int i = 0; i < n - 2 * tr; i++)
		a2[vec[tr * 2 + i].sc] = vec[tr * 2 + i].fs - a1[vec[tr * 2 + i].sc];
	for (int i = 0; i < n; i++)
		printf("%d ", a1[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", a2[i]);
	printf("\n");

	return 0;
}