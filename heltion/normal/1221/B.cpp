//Author: Heltion
//Date: 09-19-2019
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
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		for(int j = 0; j < n; j += 1) cout << "WB"[(i + j) & 1];
		cout << "\n";
	}
	return 0;
}