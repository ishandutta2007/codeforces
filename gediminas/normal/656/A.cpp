/*input


*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	long long n;
	cin >> n;
	long long mas[36]={1};
	for(int i = 1;i<13;i++){
	    mas[i]=mas[i-1]*2;
	}
	mas[13]=8092;
	for(int i = 14;i<36;i++){
	    mas[i]=mas[i-1]*2;
	}
	cout << mas[n];


	return 0;
}