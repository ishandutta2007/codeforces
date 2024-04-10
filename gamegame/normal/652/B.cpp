#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int x;
	cin >> x;
	int a[x+1];
	for(int i=1; i<=x ;i++){
		cin >> a[i];
	}
	sort(a+1,a+x+1);
	int b[x+1];
	for(int i=3; i<=x ;i+=2){
		swap(a[i-1],a[i]);
	}
	for(int i=1; i<x ;i++){
		cout << a[i] << ' ';
	}
	cout << a[x] << endl;
}