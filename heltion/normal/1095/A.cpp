#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n >> s;
	for(int i = 1, j = 0; j < n; j += i, i += 1) cout << s[j];
}