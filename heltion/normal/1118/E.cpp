#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto read = [](){LL x; cin >> x; return x;};
auto no = [](){cout << "NO"; exit(0);};
#define maxn 240000
LL a[maxn];
int main(){
	ios::sync_with_stdio(false);
	LL n = read(), k = read();
	if(k * k - k < n) no();
	cout << "YES" << endl;
	int a = 1, b = 2;
	for(int i = 0; i < n; i += 1)
		if(i % 2 == 0) cout << a << " " << b << endl;
		else{
			cout << b << " " << a << endl;
			b += 1;
			if(b > k){
				a += 1;
				b = a + 1;
			}
		}
}