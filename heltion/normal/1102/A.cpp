#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(n % 2) cout << ((n + 1) % 4 > 0);
	else cout << (n % 4 > 0);
}