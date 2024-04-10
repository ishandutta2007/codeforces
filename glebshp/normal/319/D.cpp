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
const int size = 50 * 1000 + 100;

char buf[size];

int main() {
	/*
	freopen("problem_d.in", "w", stdout);
	for (int i = 0; i < 12500; i++)
		printf("ab");
	for (int i = 0; i < 25 * 1000; i++)
		printf("a");
	printf("\n");
	return 0;
	*/
	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	double sttm = clock();
	scanf("%s", buf);
	int n = strlen(buf);
	int p;
	int ps;
	int len;
	while (true) {
		ps = -1;
		len = -1;
		for (int i = 1; i <= n / 2; i++) {
			int p = 0;
			int lim = n - 2 * i;
			for (int j = 0; j <= lim; j++) {
				while (p < i && buf[j + p] == buf[j + i + p])
					p++;
				if (p == i) {
					len = i;
					ps = j;
					break;
				}
				if (p > 0)
					p--;
			}
			if (ps != -1)
				break;
		}
		if (ps == -1)
			break;
		for (int j = ps + len; j < n - len; j++)
			buf[j] = buf[j + len];
		n -= len;
	}
	buf[n] = '\0';
	printf("%s\n", buf);

	//cout << (clock() - sttm) / CLOCKS_PER_SEC << endl;

	return 0;
}