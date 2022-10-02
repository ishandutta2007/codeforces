#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set> 


using namespace std;


int n;
int c[100000];
int ans = 1000000000;


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c, c + n);
	int l = n - 1;
	while (c[l] > 2 * c[0]) {
		l--;
	}
	for (int i = 0; i <= n - 1; i++) {
		while (l < n - 1 && c[l + 1] <= 2 * c[i]) {
			l++;
		}
		ans = min(ans, i + (n - l - 1));
	}
	cout << ans << endl;
    return 0;
}