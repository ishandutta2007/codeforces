#include<bits/stdc++.h>
#define maxn
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(false);
	LL n, k;
	cin >> n >> k;
	cout << (2 * n + k - 1) / k + (5 * n + k - 1) / k + (8 * n + k - 1) / k;
}