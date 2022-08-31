#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int num=(n+1)/3;
	for(int i=1; i<=n ;i++){
		if(i<=n-num) cout << i%2 << ' ' << i << endl;
		else cout << 2 << ' ' << (i-n+num)*2 << endl;
	}
}