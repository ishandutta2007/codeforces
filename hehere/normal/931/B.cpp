// Codeforces Round #468 (Div. 2, based on Technocup 2018 Final Round)
// B
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'%c", __LINE__, __FUNCTION__, 10);
int n, a, b;

int solve(int d, int L, int R) {
	int M = L + R >> 1;
	if(L <= a && a <= M && L <= b && b <= M) return solve(d+1, L, M);
	if(M < a && a <= R && M < b && b <= R) return solve(d+1, M+1, R);
	return d;
}

int main(){
	std::cin >> n >> a >> b;
	int cnt = 0;
	for(int i=n; i; i>>=1) cnt++;
	int ans = cnt - solve(1, 1, n);
	if(ans == cnt - 1) std::cout << "Final!\n";
	else std::cout << ans << "\n";
	
	return 0;
}