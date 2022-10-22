#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, x, y;
	scanf("%I64d%I64d%I64d", &n, &x, &y);
	long long d1 = max(x - 1, y - 1), d2 = max(n - x, n - y);
	printf(d1 > d2 ? "Black\n" : "White\n");
	return 0;
}