#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#include <vector>
#include <utility>


#include <algorithm>


void solve() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", max(a,max(b,c)) - min(a,min(b,c)));
}


int main() {
    solve();
}