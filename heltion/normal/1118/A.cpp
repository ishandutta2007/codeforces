#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto read = [](){LL x; cin >> x; return x;};
auto no = [](){cout << "No"; exit(0);};
int main(){
	ios::sync_with_stdio(false);
	int q = read();
	while(q --){
		LL n = read(), a = read(), b = read();
		b = min(b, a * 2);
		cout << n / 2 * b + n % 2 * a << endl;
	}
}