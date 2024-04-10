// Author: Heltion
// Date: 2019-04-26
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL f(LL n){
	n += 1;
	while(n % 10 == 0) n /= 10;
	return n;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	set<LL> s;
	LL n;
	cin >> n;
	while(true){
		s.insert(n);
		n = f(n);
		if(s.count(n)) break;
	}
	cout << s.size();
	return 0;
}