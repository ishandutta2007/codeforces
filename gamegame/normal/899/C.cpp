#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
int a[25];
int b[73];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	if(n%4==0){
		cout << 0 << endl << n/2;
		for(int i=1; i<=n/4 ;i++){
			cout << ' ' << i << ' ' << n-i+1;
		}
	}
	else if(n%4==3){
		cout << 0 << endl << n/2;
		for(int i=1; i<=n/4 ;i++){
			cout << ' ' << i << ' ' << n-i;
		}
		cout << ' ' << n << endl;
	}
	else if(n%4==2){
		cout << 1 << endl << n/2;
		for(int i=3; i<=n/4+2 ;i++){
			cout << ' ' << i << ' ' << n-i+3;
		}
		cout << " 1\n";
	}
	else{
		cout << 1 << endl << n/2;
		for(int i=2; i<=n/4+1 ;i++){
			cout << ' ' << i << ' ' << n-i+2;
		}
	}
}