#include<stdio.h>
#include<map>
using namespace std;
map<pair<pair<int, int>, long long int>, long long int> dptable;
long long int s;
long long int calc(int a, int b, long long int c) {
	if (a > b)return calc(b, a, c);
	if (c < 0 || c>(1LL << (a+1)) + (1LL << (b+1)) - 2)return 0;
	if (a == 0) {
		while (b>0) {
			if (c >= (1LL << b) - 1)c -= (1LL << b) - 1;
			b--;
		}
		if (c == 0)return 1;
		else return 0;
	}
	if (dptable.find(make_pair(make_pair(a, b), c))!=dptable.end())return dptable[make_pair(make_pair(a, b), c)];
	long long int res = 0;
	if (a < b) {
		res += calc(a, b - 1, c);
		res += calc(a, b - 1, c - ((1LL << b) - 1));
	}
	else {
		res += calc(a - 1, b - 1, c);
		res += calc(a - 1, b - 1, c - ((1LL << a) - 1));
		res += calc(a - 1, b - 1, c - ((1LL << b) - 1));
		res += calc(a - 1, b - 1, c - ((1LL << a) - 1) - ((1LL << b) - 1));
	}
	dptable[make_pair(make_pair(a, b), c)] = res;
	return res;
}
int main() {
	scanf("%I64d", &s);
	long long int ans = 0;
	for (int i = 0; i < 53; i++) {
		for (int j = 0; j < 53; j++) {
			if (i == 0) {
				if (j == 0) {
					ans++;
				}
				else {
					long long int root = s / ((1LL << (j + 1)) - 1);
					if (root == 0)continue;
					ans += calc(0, j - 1, s - (root*((1LL << (j + 1)) - 1)) - ((1LL << j) - 1));
				}
			}
			else {
				if (j == 0) {
					long long int root = s / ((1LL << (i+1)) - 1);
					if (root == 0)continue;
					ans += calc(i - 1, 0, s - (root*((1LL << (i + 1)) - 1)));
				}
				else {
					long long int root = s / ((1LL << (i + 1)) + (1LL << (j + 1)) - 3);
					if (root == 0)continue;
					ans += calc(i - 1, j - 1, s - (root*((1LL << (i + 1)) + (1LL << (j + 1)) - 3)) - ((1LL << j) - 1));
				}
			}
		}
	}
	printf("%I64d", ans);
	return 0;
}