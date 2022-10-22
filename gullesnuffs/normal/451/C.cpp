#include <bits/stdc++.h>

using namespace std;

bool solve(long long a, long long b, long long c, long long n, long long k){
	long long g1=k-a-b-c;
	if(g1 < 0)
		g1=-g1;
	if(g1%3)
		return false;
	long long Min=min(min(a, b), c);
	if(a+b+c-3*Min > k)
		return false;
	long long need=max(max(a, b), c);
	long long gamesLeft=need*3-a-b-c;
	if(gamesLeft > n-k)
		return false;
	if(n%3)
		return false;
	return true;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long n, k, d1, d2;
		scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
		if(solve(d1, 0, d2, n, k) || solve(d1, 0, -d2, n, k) ||
				solve(-d1, 0, d2, n, k) || solve(-d1, 0, -d2, n, k))
			puts("yes");
		else
			puts("no");

	}
}