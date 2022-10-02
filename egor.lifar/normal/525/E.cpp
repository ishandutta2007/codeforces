#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


int n, k;
long long s;
int a[25];
map<long long, long long> c[26];
long long fact[19];
long long ans = 0;
int t = 0;
long long sum = 0;


void get(int i) {
	if (sum > s) {
		return;
	}
	if (i == n / 2) {
		c[t][sum]++;
		return;
	}
	get(i + 1);
	sum += 1LL * a[i];
	get(i + 1);
	sum -= 1LL * a[i];
	if (a[i] < 19) {
		sum += fact[a[i]];
		t++;
		get(i + 1);
		t--;
		sum -= fact[a[i]];
	}
}


void get1(int i) {
	if (sum > s) {
		return;
	}
	if (i == n) {
		for (int g = 0; g <= k - t; g++) {
			if (c[g].count(s - sum)) {
				ans += c[g][s - sum];
			}
		}	
		return;
	}
	get1(i + 1);
	sum += 1LL * a[i];
	get1(i + 1);
	sum -= 1LL * a[i];
	if (a[i] < 19) {
		sum += fact[a[i]];
		t++;
		get1(i + 1);
		t--;
		sum -= fact[a[i]];
	}
}


int main() {
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	fact[1] = 1;
	for (int i = 2; i < 19; i++) {
		fact[i] = fact[i - 1] * 1LL * i;
	}
	get(0);
	get1(n / 2);
	cout << ans << endl;
    return 0;
}