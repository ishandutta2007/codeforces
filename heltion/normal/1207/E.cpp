//Author: Heltion
//Date: 08-22-2019
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
	int a, b, x = 5;
	cout << "? ";
	for(int i = 1; i <= 100; i += 1) cout << i << " ";
	cout << endl;
	cin >> a;
	//a = x ^ (rand() % 100);
	cout << "? ";
	for(int i = 1; i <= 100; i += 1) cout << (i << 7) << " ";
	cout << endl;
	cin >> b;
	//b = x ^ ((rand() % 100) << 7);
	cout << "! " << (a >> 7 << 7) + (b & ((1 << 7) - 1));
	return 0;
}