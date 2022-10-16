/*input
4 1 1
1 1 2 1
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, a, b;
	cin >> n >> a >> b;
	int c = 0;
	int k = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x==2){
			if(b>0)
				b--;
			else
				k+=2;
		}else{
			if(a>0){
				a--;
				//cout << "A";
			}
			else if(b>0){
				b--;
				c++;
				//cout << "B";
			}
			else if(c>0){
				c--;
				//cout << "C";
			}
			else
				k++;
		}
	}

	cout << k << endl;

	return 0;
}