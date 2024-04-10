#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;
typedef pair<pi2, pi2> pi4;
using ll = long long;
using pl2 = pair<ll, ll>;



void Main(){
	string s; cin >> s;
	bool ans = 0;
	for (char c : s){
		if (c=='H' || c=='Q' || c=='9'){ ans = 1; }
	}
	if (ans){ cout << "YES"; }
	else{ cout << "NO"; }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}