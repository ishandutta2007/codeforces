#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	int n, x = 0;
	cin >> n;
	while(n --){
		int a;
		cin >> a;
		x |= a & 1;
	}
	cout << (x ? "First" : "Second");
}