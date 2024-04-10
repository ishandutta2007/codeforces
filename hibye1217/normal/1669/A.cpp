#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;



void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		if (1900 <= n){ cout << "Division 1" << endl; }
		else if (1600 <= n){ cout << "Division 2" << endl; }
		else if (1400 <= n){ cout << "Division 3" << endl; }
		else{ cout << "Division 4" << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}