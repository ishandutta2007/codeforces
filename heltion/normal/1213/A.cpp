//Author: Heltion
//Date: 08-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int s[2] = {0, 0}, n, x;
	for(cin >> n; n; n -= 1){
		cin >> x;
		s[x % 2] += 1;
	}
	cout << min(s[0], s[1]);
	return 0;
}