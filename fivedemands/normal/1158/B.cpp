#include<iostream>
using namespace std;
int n,k;
int a[100000];
int main(){
	cin >> n >> k;
	int bs=(n-k+2)/2;
	if(n==k){
		for(int i=0; i<n ;i++) cout << "1";
	}
	else if(k==1){
		cout << "0";
		for(int i=1; i<n ;i++) cout << "1";
	}
	else{
		for(int i=0; i<n ;i++){
			if(i%((n-k+2)/2)==0) cout << "1";
			else cout << "0";
		}
	}
	if(true);
	else if(k%2==1){
		for(int i=0; i<n ;i++){
			if(i==0 || i==n-1 || i==(n+k-2)/2 || (i==(n-k)/2) || i==(n-1)/2) cout << "1";
			else cout << "0";
		}
	}
	else{
		for(int i=0; i<n ;i++){
			if(i<=(k-2)/2 || i>=(2*n-k)/2 || (i<=(n+k-2)/2 && i>=(n-k)/2)) cout << "1";
			else cout << "0";
		}
	}
}