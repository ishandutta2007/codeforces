#include<bits/stdc++.h>
#define maxn 240000
using namespace std;
typedef long long LL;
int main(){
	LL n;
	cin >> n;
	for(LL i = 2; i * i <= n; i += 1)if(n % i == 0){
		cout << (n - i) / 2 + 1;
		return 0;
	}
	cout << 1;
}