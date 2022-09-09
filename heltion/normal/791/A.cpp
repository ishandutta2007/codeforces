#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, d = 0;
	cin >> a >> b;
	while(a <= b){
		d += 1;
		a *= 3;
		b *= 2;
	}
	cout << d;
}