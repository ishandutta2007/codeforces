#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q --){
		LL l, r, d;
		cin >> l >> r >> d;
		if(l > d) cout << d << endl;
		else cout << (r / d + 1) * d << endl;
	}	
}