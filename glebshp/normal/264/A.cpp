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
#include <deque>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

const int size = 2 * 1000 * 1000;
char buf[size];

int main() {
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	scanf("%s", buf);
	int n = strlen(buf);

	deque <int> dq;
	for (int i = n - 1; i >= 0; i--)
		if (buf[i] == 'l')
			dq.push_back(i + 1);
		else
			dq.push_front(i + 1);
	while (!dq.empty()) {
		printf("%d\n", dq.front());
		dq.pop_front();
	}

	return 0;
}