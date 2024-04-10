#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string a, b;
	cin >> a >> b;
	int s = 0, ans = 0;
	for(int i = 0; i < (int)b.size(); i += 1) s ^= (a[i] - '0') ^ (b[i] - '0');
	for(int i = 0; i + b.size() - 1 < a.size(); i += 1){
		ans += s ^ 1;
		if(i + b.size() < a.size()) s ^= (a[i] - '0') ^ (a[i + b.size()] - '0');
	}
	cout << ans;
	return 0;
}