//Author: Heltion
//Date: 07-31-2019
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
	LL r;
	cin >> r;
	for(LL x = 1; x * x + x + 1 < r; x += 1)
		if((r - x * x - x - 1) % (2 * x) == 0){
			cout << x << " " << (r - x * x - x - 1) / (2 * x);
			return 0;
		}
	cout << "NO";
	return 0;
}