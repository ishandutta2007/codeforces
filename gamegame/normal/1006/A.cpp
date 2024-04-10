#include<iostream>
using namespace std;
int a[1001];
int main(){
	int t;
	cin >> t;
	for(int i=1; i<=t ;i++){
		cin >> a[i];;
		if(a[i]%2==0) a[i]--;
		cout << a[i] << ' ';
	}
}