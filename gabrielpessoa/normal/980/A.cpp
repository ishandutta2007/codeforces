#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int SIZE = 105;


int main(){
	string s;
	cin >> s;
	int x = 0, y = 0;
	for(char c : s) {
		if(c == '-') y++;
		else x++;
	}
	if(!x || y % x == 0) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}