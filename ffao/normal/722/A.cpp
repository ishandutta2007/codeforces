#include <stdio.h>
#include <bits/stdc++.h>

 
#include <vector>
#include <utility>


#include <algorithm>


int fmt, hr, mn;

void solve() {
	scanf("%d %d:%d", &fmt, &hr, &mn);

	if (mn >= 60) mn = mn % 10;

	if (fmt == 12 && (hr < 1 || hr > 12)) {
		if (hr%10 == 0) hr = 10;
		else hr = (hr%10);
	}
	if (fmt == 24 && hr >= 24) hr = 10 + (hr % 10);

	printf("%02d:%02d\n", hr,mn);
}


int main() {
    solve();
}