/*input
7
3 3 3 3 3 3 3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int stad = 1;
	int buv = INT_MIN;
	for(int i = 0; i < n; i++) {
		int d;
		cin >> d;
		if(buv<d and stad<=1){
			stad=1;
		}else if(buv==d and stad<=2){
			stad=2;
		}else if(buv>d and stad<=3){
			stad=3;
		}else{
			cout << "NO";
			return 0;
		}
		buv = d;
	}

	cout << "YES";
	return 0;
}