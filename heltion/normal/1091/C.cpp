#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

set<LL> s; 
LL n;
LL c(int i){
	return (n + 2 - i) * n / i / 2;
}
int main(){
	ios::sync_with_stdio(false);
	
	cin >> n;
	for(LL i = 1; i * i <= n; i += 1) if(n % i == 0){
		s.insert(c(i));
		s.insert(c(n / i));
	}
	for(LL x : s) cout << x << " ";
}