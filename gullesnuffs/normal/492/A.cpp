#include <bits/stdc++.h>

using namespace std;

int main(){
	int sz=1;
	int n;
	cin >> n;
	int i;
	for(i=1; true; ++i){
		n -= sz;
		sz += i+1;
		if(n < 0)
			break;
	}
	cout << (i-1) << endl;
}