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


const int size = 50 * 1000 + 100;
char buf[size];


int main() {
	scanf("%s", buf);
	int n = strlen(buf);
	while (true) {
		int ps = -1;
		int len = -1;
		for (int i = 1; i <= n / 2; i++) {
			int p = 0;
			int lim = n - 2 * i;
			for (int j = 0; j <= lim; j++) {
				while (p < i && buf[j + p] == buf[j + i + p]) {
					p++;
				}
				if (p == i) {
					len = i;
					ps = j;
					break;
				}
				if (p > 0) {
					p--;
				}
			}
			if (ps != -1) {
				break;
			}
		}
		if (ps == -1) {
			break;
		}
		for (int j = ps + len; j < n - len; j++) {
			buf[j] = buf[j + len];
		}
		n -= len;
	}
	buf[n] = '\0';
	printf("%s\n", buf);
	return 0;
}