#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,p,l,r;
	cin >> n >> p >> l >> r;
	if(l==1){
		if(r==n) cout << 0 << endl;
		else cout << abs(p-r)+1 << endl;
	}
	else{
		if(r==n) cout << abs(p-l)+1 << endl;
		else cout << min(abs(p-l),abs(p-r))+r-l+2 << endl;
	}
}