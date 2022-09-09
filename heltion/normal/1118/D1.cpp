#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto read = [](){LL x; cin >> x; return x;};
auto no = [](){cout << "-1"; exit(0);};
#define maxn 240000
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n = read();
	LL m = read(), s = 0;
	for(int i = 0; i < n; i += 1){
		a[i] = read();
		s += a[i];
	}
	if(s < m) no();
	sort(a, a + n, greater<LL>());
	int L = 1, R = n;
	while(L < R){
		int M = (L + R) >> 1;
		s = 0;
		for(int i = 0; i < n; i += 1) s += max(0LL, a[i] - i / M);
		if(s >= m) R = M;
		else L = M + 1;
	}
	cout << L;
}