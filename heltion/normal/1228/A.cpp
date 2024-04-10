//Author: Heltion
//Date: 09-29-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;
bool test(int x){
	bool vis[10] = {false};
	for(; x; x /= 10){
		if(vis[x % 10]) return false;
		vis[x % 10] = true;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int l, r;
	cin >> l >> r;
	for(int x = l; x <= r; x += 1) if(test(x)) no(x);
	cout << -1;
	return 0;
}