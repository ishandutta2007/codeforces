//Author: Heltion
//Date: 07-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 0;
void no(){cout << "NO"; exit(0);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	LL n, k;
	cin >> n >> k;
	//(1 + n - m) * (n - m) / 2 - m = k
	LL d = sqrt(8 * k + 8 * n + 9) + 0.5;
	cout << (2 * n + 3 - d) / 2;
	return 0;
}