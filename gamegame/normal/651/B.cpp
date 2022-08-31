#include<iostream>
using namespace std;
int main(){
	int x,p;
	int a[1001];
	for(int i=0; i<=1000 ;i++){
		a[i]=0;
	}
	cin >> x;
	for(int i=1; i<=x ;i++){
		cin >> p;
		a[p]++;
	}
	int maxi=0;
	for(int i=0; i<=1000 ;i++){
		maxi=max(maxi,a[i]);
	}
	cout << x-maxi << endl;
}