#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string m;
	cin >> m;
	m=' '+m;
	int a[n+1];
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	int pos=1;
	for(int i=1; i<=n+1 ;i++){
		if(pos>n || pos<1){
			cout << "FINITE\n";
			return 0;
		}
		if(m[pos]=='>'){
			pos+=a[pos];
		}
		else{
			pos-=a[pos];
		}
	}
	cout << "INFINITE\n";
}