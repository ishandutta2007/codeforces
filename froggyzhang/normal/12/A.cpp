#include <bits/stdc++.h>
using namespace std;
char a[4][4];
int main(){
	for (int i = 1; i <= 3; i++){
			for (int j = 1; j <= 3; j++){
					cin >> a[i][j];
				}
		}
	if(a[1][1] == a[3][3] && a[2][1] == a[2][3] && a[3][1] == a[1][3] && a[1][2] == a[3][2]){cout << "YES";}	
	else{cout << "NO";}
	return 0;			
 }