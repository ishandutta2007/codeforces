#include<bits/stdc++.h>
#define maxn
using namespace std;
typedef long long LL;
LL s(LL n){
	return n % 2 ? n / 2 - n : n / 2;
}
int main(){
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q --){
		LL l, r;
		cin >> l >> r;
		cout << s(r) - s(l - 1) << endl;
	}
}