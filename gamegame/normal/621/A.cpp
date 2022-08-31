#include<iostream>
using namespace std;
int main(){
	int x;
	cin >> x;
	long long int a[x];
	long long int sum=0;
	long long int mo=2e9;
	for(int i=0; i<x ;i++){
		cin >> a[i];
		if(a[i]%2==1 && a[i]<mo){
			mo=a[i];
		}
		sum+=a[i];
	}
	if(sum%2==0){
		cout << sum << endl;
	}
	else{
		cout << sum-mo << endl;
	}
}