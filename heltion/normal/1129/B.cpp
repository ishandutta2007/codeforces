#include<bits/stdc++.h>
#define maxn 6000
using namespace std;
typedef long long LL;
void test(int k, int n){
	for(int x = n - k % n; x <= 1000000; x += n){
		int m = x - (k + x) / n;
		if(m <= 0) continue;
		cout << n << endl;
		for(int i = 1; i <= n - 2; i += 1) cout << "0 ";
		cout << -m << " " << x;
		exit(0);
	}
}
int main(){
	ios::sync_with_stdio(false);
	int k;
	cin >> k;
	for(int n = 2; n <= 2000; n += 1) test(k, n);
	assert(0);
}