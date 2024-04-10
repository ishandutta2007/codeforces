#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;



void Main(){
	string s; cin >> s;
	int cnt = 0;
	for (char c : s){
		cnt += (c=='4' | c=='7');
	}
	if (cnt == 4 || cnt == 7){ cout << "YES"; }
	else{ cout << "NO"; }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}