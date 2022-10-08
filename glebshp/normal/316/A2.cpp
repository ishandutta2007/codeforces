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

const int size = 200 * 1000 + 100;

char buf[size];

int main() {
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	scanf("%s", buf);
	int n = strlen(buf);
	set <char> smbs;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (buf[i] == '?')
			cnt++;
		if (buf[i] >= 'A' && buf[i] <= 'J')
			smbs.insert(buf[i]);
	}
	int cnt2 = smbs.size();
	long long ans = 1;
	if (buf[0] == '?') {
		ans = 9;
		cnt--;
		for (int i = 0; i < cnt2; i++)
			ans *= (10 - i);
	} else if (buf[0] >= 'A' && buf[0] <= 'J') {
		ans = 9;
		for (int i = 1; i < cnt2; i++)
			ans *= (10 - i);
	} else {
		for (int i = 0; i < cnt2; i++)
			ans *= (10 - i);
	}

	printf("%I64d", ans);
	for (int i = 0; i < cnt; i++)
		printf("0");
	printf("\n");

	return 0;
}