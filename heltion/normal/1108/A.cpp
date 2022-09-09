#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q --){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << a << " ";
		if(c != a) cout << c << endl;
		else cout << d << endl;
	} 
}