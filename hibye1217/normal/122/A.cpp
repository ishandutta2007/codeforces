#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;

void Main(){
	int n; cin >> n;
	for (int x : {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777}){
		if (n % x == 0){ cout << "YES"; return; }
	}
	cout << "NO";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}