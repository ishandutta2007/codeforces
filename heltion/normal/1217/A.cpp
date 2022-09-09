//Author: Heltion
//Date: 09-05-2019
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
	int T;
	for(cin >> T; T; T -= 1){
		int s, i, e;
		cin >> s >> i >> e;
		//i + x < s + e - x
		//2 * x < s + e - i
		//x < (s + e - i + 1) / 2
		cout << max(min((s + e - i + 1) / 2, e + 1), 0) << "\n";
	}
	return 0;
}