#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
typedef long long LL;
LL k[maxn];
int main(){
	int n;
	cin >> n;
	LL ans = 0;
	for(int i = 2; i <= n; i += 1){
		ans += k[i];
		for(int j = i; j <= n; j += i)
			k[j] += j / i;
	}
	cout << ans * 4;
}