#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A, B, C;

bool go() {
	B -= A;
	if(B == 0) return true;
	if(C * B <= 0) return false;
	if(B % C == 0) return true;
	return false;
}

int main() {
	cin >> A >> B >> C;
	cout << (go() ? "YES" : "NO") << '\n';
	return 0;
}