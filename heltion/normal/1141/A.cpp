#include<bits/stdc++.h>
using namespace std;
void no(){cout << -1; exit(0);}
int main(){
	int n, m, ans = 0;
	cin >> n >> m;
	if(m % n) no();
	m /= n;
	while(m % 2 == 0) m /= 2, ans += 1;
	while(m % 3 == 0) m /= 3, ans += 1;
	if(m > 1) no();
	cout << ans;
}