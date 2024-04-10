#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
auto no = [](){cout << "NO"; exit(0);};
auto read = [](){int x; cin >> x; return x;};
#define maxn 120
set<int> s;
int a[maxn];
int t = 0;
int wenhao(int i){
	assert(++ t <= 60);
	cout << "? " << i << endl;
	int res = read();
	assert(res != -1);
	return res;
}
int dayuhao(int x){
	assert(++ t <= 60);
	cout << "> " << x << endl;
	int res = read();
	assert(res != -1);
	return res;
}
const int lim = 30;
int main(){
	ios::sync_with_stdio(false);
	srand(time(0) + (LL)"fuck");
	int n;
	cin >> n;
	for(int i = 0; i < lim; i += 1) a[i] = wenhao(((rand() << 14) + rand()) % n + 1);
	sort(a, a + lim);
	int m = unique(a, a + lim) - a;
	for(int i = m - 1; i; i -= 1) a[i] -= a[i - 1];
	LL d = a[1];
	for(int i = 1; i < m; i += 1) d = __gcd(d, (LL)a[i]);
	int L = 0, R = 1000000000;
	while(L <= R){
		LL M = (L + R) >> 1;
		if(dayuhao(M)) L = M + 1;
		else R = M - 1;
	}
	assert(L - (n - 1) * d >= 0 && d > 0);
	cout << "! " << L - (n - 1) * d << " " << d << endl;
}