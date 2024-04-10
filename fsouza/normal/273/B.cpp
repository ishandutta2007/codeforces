#include <iostream>
#include <cstdio>
#include <map>

#define MAXN 100010

typedef long long lint;

using namespace std;

int as[MAXN], bs[MAXN];

int main()
{
	int n;
	map <int, int> xs;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &as[i]);
		xs[as[i]] ++;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &bs[i]);
		xs[bs[i]] ++;
	}

	int neq = 0;
	for (int i = 0; i < n; i++)
		neq += as[i] == bs[i];

	int _m;

	scanf("%d", &_m);
	lint m = _m;

	lint ret = 1;

	for (map <int, int>::iterator it = xs.begin(); it != xs.end(); it++) {
		int much = it -> second;
		for (lint i = 2; i <= much; i++) {
			lint multby = i;
			while ((multby%2 == 0) && neq) {
				neq --;
				multby /= 2;
			}
			ret = (ret * multby)%m;
		}
	}

	printf("%d\n", (int)ret);

	return 0;
}